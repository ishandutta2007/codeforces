#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<climits>
#include<iomanip>
#include<ctime>
#include<math.h>
#include<cmath>
#include<algorithm>
#include<functional>
#include<set>
#include<map>
#include<vector>
#include<stack>
#include<queue>
#include<bitset>
#include<complex>
#include<cstring>
#include<string>
#include<deque>
#define re register
#define ri register int
#define ll long long
#define pii pair<int,int>
#define F(i,a,b) for(register int i=a,i##end=b;i<=i##end;++i)
#define UF(i,a,b) for(register int i=a,i##end=b;i>=i##end;--i)
using namespace std;
inline int read(){
	int rt;
	cin>>rt;
	return rt;
}
template<class T>
inline void read(T &rt){
	cin>>rt;
}
char _n_u_m_[40],_c_n_t_;
template<class T>
inline void write(T x){
	cout<<x;
}
template<class T>
inline void write(T x,char c){
	write(x);
	putchar(c);
}
int n;
char c[502];
#define vi vector<int>
vector<int>query(string x){
	cout<<"? "<<x<<endl;
	fflush(stdout);
	vector<int>rt;
	ri qwq=read();
	rt.resize(qwq);
	F(i,0,qwq-1){
		read(rt[i]);
		F(j,0,x.size()-1)c[rt[i]+j]=x[j];
	}
	return rt;
}
inline void ak(int x,int y){
	string temp;
	F(i,1,n)temp.push_back(c[i]);
	bool t1=temp[x-1],t2=temp[y-1];
	if(!t1)temp[x-1]='H';
	if(!t2)temp[y-1]='C';
	query(temp);
	if(!t2)temp[y-1]='H';
	query(temp);
	if(!t2)temp[y-1]='O';
	query(temp);
	if(!t1)temp[x-1]='O';
	if(!t2)temp[y-1]='C';
	query(temp);
	if(!t2)temp[y-1]='H';
	query(temp);
	if(!t2)temp[y-1]='O';
	query(temp);
}
inline void solve(){
	cin>>n;
	memset(c,0,sizeof(c));
	c[n+1]='\0';
	if(n==4){
		query("CC");
		query("CH");
		query("CO");
		if(c[1])ak(3,4);
		else if(c[2])ak(1,4);
		else if(c[3])ak(1,2);
		else{
			query("HO");
			if(c[1])ak(3,4);
			else if(c[2])ak(1,4);
			else if(c[3])ak(1,2);
			else{
				query("OO");
				if(c[1]&&c[2]&&c[3]&&c[4]);
				else if(c[1]&&c[2]&&c[3]){
					if(!query("OOOH").size())c[4]='C';
				}else if(c[1]&&c[2]){
					c[3]='H';
					if(!query("OOHH").size())c[4]='C';
				}else{
					c[2]=c[3]='H';
					query("HHH");
					if(!c[1])c[1]='O';
					if(!c[4])c[4]='C';
				}
			}
		}
	}else{
		query("CC");
		query("CH");
		query("CO");
		query("HO");
		query("OH");
		F(i,1,n-1){
			if(c[i-1]&&!c[i]){
				c[i]=c[i-1];
			}
		}
		if(!c[1]){
			string temp;
			temp.clear();
			temp.push_back('H');
			F(i,2,n-1){
				if(c[i])temp.push_back(c[i]);
				else temp.push_back('H');
			}
			query(temp);
			if(!c[1]){
				F(i,1,n-1)if(!c[i])c[i]='O';
			}
		}if(!c[n]){
			string temp;
			temp.clear();
			F(i,1,n-1)temp.push_back(c[i]);
			temp.push_back('C');
			query(temp);
			if(!c[n])c[n]=c[n-1];
		}
	}
	cout<<"! ";
	puts(c+1);
	fflush(stdout);
}
int main(){
	F(qwq,1,read()){
		solve();
		read();
	}
	return 0;
}