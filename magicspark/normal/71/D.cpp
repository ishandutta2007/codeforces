//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int calc1(char c){
	if(c=='C')return 1;
	if(c=='D')return 2;
	if(c=='H')return 3;
	if(c=='S')return 4;
}
inline calc2(char c){
	if(isdigit(c))return c-'0';
	if(c=='T')return 10;
	if(c=='J')return 11;
	if(c=='Q')return 12;
	if(c=='K')return 13;
	if(c=='A')return 1;
}
inline char get1(int x){
	if(x==1)return 'C';
	if(x==2)return 'D';
	if(x==3)return 'H';
	if(x==4)return 'S';
}
inline char get2(int x){
	if(2<=x&&x<10)return '0'+x;
	if(x==10)return 'T';
	if(x==11)return 'J';
	if(x==12)return 'Q';
	if(x==13)return 'K';
	if(x==1)return 'A';
}
bool cross(int i1,int j1,int i2,int j2){
	vector<int>s1,s2;
	for(int i=i1;i<i1+3;i++){
		for(int j=j1;j<j1+3;j++){
			s1.push_back(i*100+j);
		}
	}
	for(int i=i2;i<i2+3;i++){
		for(int j=j2;j<j2+3;j++){
			s2.push_back(i*100+j);
		}
	}
	for(auto p:s1)for(auto q:s2)if(p==q)return true;
	return false;
}
bool ok(int x,int y,vector<vector<pair<int,int> > >&mat){
	bool samecolor=true;
	for(int i=x;i<x+3;i++){
		for(int j=y;j<y+3;j++){
			if(mat[i][j].first!=mat[x][y].first)samecolor=false;
		}
	}
	bool difranks=true;
	set<int>all;
	for(int i=x;i<x+3;i++){
		for(int j=y;j<y+3;j++){
			if(all.count(mat[i][j].second))difranks=false;
			all.insert(mat[i][j].second);
		}
	}
	return samecolor|difranks;
}
pair<pair<int,int>,pair<int,int> >check(vector<vector<pair<int,int> > >mat){
	int n=mat.size(),m=mat[0].size();
	for(int i1=0;i1<=n-3;i1++){
		for(int j1=0;j1<=m-3;j1++){
			for(int i2=0;i2<=n-3;i2++){
				for(int j2=0;j2<=m-3;j2++){
					if(!cross(i1,j1,i2,j2)&&ok(i1,j1,mat)&&ok(i2,j2,mat)){
						return make_pair(make_pair(i1+1,j1+1),make_pair(i2+1,j2+1));
					}
				}
			}
		}
	}
	return make_pair(make_pair(-1,-1),make_pair(-1,-1));
}
int n,m;
int main(){
	cin>>n>>m;
	vector<vector<pair<int,int> > >card(n,vector<pair<int,int> >(m,make_pair(0,0)));
	int cntj=0;
	vector<pair<int,int> >jokers;
	vector<string>vs;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			string s;
			cin>>s;
			if(s[0]=='J'&&isdigit(s[1])){
				cntj++;
				jokers.push_back(make_pair(i,j));
				vs.push_back(s);
				card[i][j]=make_pair(-1,-1);
				continue;
			}
			card[i][j]=make_pair(calc1(s[1]),calc2(s[0]));
			//color rank
		}
	}
	set<pair<int,int> >S;
	for(int i=1;i<=4;i++)for(int j=1;j<=13;j++)S.insert(make_pair(i,j));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(card[i][j].first!=-1){
				S.erase(S.find(card[i][j]));
			}
		} 
	}
	vector<pair<int,int> >restcards(S.begin(),S.end());
	if(cntj==0){
		auto p=check(card);
		if(p.first.first!=-1){
			puts("Solution exists.");
			puts("There are no jokers.");
			printf("Put the first square to (%d, %d).\n",p.first.first,p.first.second);
			printf("Put the second square to (%d, %d).\n",p.second.first,p.second.second);
			return 0;
		}else{
			puts("No solution.");
			return 0;
		}
	}else if(cntj==1){
		int x=jokers[0].first,y=jokers[0].second;
		for(auto p:restcards){
			card[x][y]=p;
			auto _p=check(card);
			if(_p.first.first!=-1){
				puts("Solution exists.");
				printf("Replace %s with %c%c.\n",vs[0].c_str(),get2(p.second),get1(p.first));
				printf("Put the first square to (%d, %d).\n",_p.first.first,_p.first.second);
				printf("Put the second square to (%d, %d).\n",_p.second.first,_p.second.second);
				return 0;
			}
			card[x][y]=make_pair(-1,-1); 
		}
	}else{
		int x[2]={jokers[0].first,jokers[1].first},y[2]={jokers[0].second,jokers[1].second};
		for(auto p:restcards){
			for(auto q:restcards){
				if(p!=q){
					card[x[0]][y[0]]=p;
					card[x[1]][y[1]]=q;
					auto _p=check(card);
					if(_p.first.first!=-1){
						puts("Solution exists.");
						pair<char,char>c1,c2;
						if(vs[0]=="J1"){
							c1=make_pair(get2(p.second),get1(p.first));
							c2=make_pair(get2(q.second),get1(q.first));
						}else{
							c2=make_pair(get2(p.second),get1(p.first));
							c1=make_pair(get2(q.second),get1(q.first));
						}
						printf("Replace J1 with %c%c and J2 with %c%c.\n",c1.first,c1.second,c2.first,c2.second);
						printf("Put the first square to (%d, %d).\n",_p.first.first,_p.first.second);
						printf("Put the second square to (%d, %d).\n",_p.second.first,_p.second.second);
						return 0;
					}
					card[x[0]][y[0]]=make_pair(-1,-1);
					card[x[1]][y[1]]=make_pair(-1,-1);
				}
			}
		}
	}
	puts("No solution.");
	return 0;
}