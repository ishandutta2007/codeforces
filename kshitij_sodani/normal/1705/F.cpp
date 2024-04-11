#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back

mt19937 rng;

int n;
int ha=0;
int zz=0;
int ask(string aa){
	cout<<aa<<endl;
	int x;
	cin>>x;
	if(x==n){
		exit(0);
	}
	return x;
}
vector<pair<int,int>> pre;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	rng=mt19937(chrono::steady_clock::now().time_since_epoch().count());
	cin>>n;
	string tt="";
	string ee="";
	set<int> cur;
	for(int i=0;i<n;i++){
		tt+="F";
		if(i%2==0){
			ee+="F";
		}
		else{
			ee+="T";
		}
		cur.insert(i);
	}
	int x=ask(tt);
	int bb=ask(ee);
	while(cur.size() and x<n){
		ee="";
		for(int i=0;i<n;i++){
			if(i%2==0){
				ee+="F";
			}
			else{
				ee+="T";
			}
		}
		if(cur.size()<=2){
			for(auto j:cur){
				tt[j]='T';
				int y=ask(tt);
				if(y==x-1){
					tt[j]='F';
				}
			}
			break;
		}
		vector<int> aa;
		for(auto j:cur){
			aa.pb(j);
		}
	//	shuffle(aa.begin(),aa.end(),rng);
		tt[aa[0]]='T';
		tt[aa[1]]='T';
		int y=ask(tt);
		if(y==n){
			return 0;
		}
		cur.erase(aa[0]);
		cur.erase(aa[1]);
		if(y==x+2){
			x=y;
			continue;
		}
		else if(y==x-2){
			tt[aa[0]]='F';
			tt[aa[1]]='F';
			continue;
		}
		else{
			cur.erase(aa[2]);
			if(ee[aa[0]]=='F'){
				ee[aa[0]]='T';
				ee[aa[1]]='F';
			}
			else{
				ee[aa[0]]='F';
				ee[aa[1]]='T';
			}
			if(ee[aa[2]]=='F'){
				ee[aa[2]]='T';
			}
			else{
				ee[aa[2]]='F';
			}
			int bb2=ask(ee);
			vector<int> dd;
			if(bb2==bb+3){
				dd={1,1,1};
			}
			else if(bb2==bb-3){
				dd={0,0,0};
			}
			else if(bb2==bb+1){
				dd={1,1,0};
			}
			else{
				dd={0,0,1};
			}
			for(int i=0;i<3;i++){
				if(dd[i]==1){
					if(tt[aa[i]]!=ee[aa[i]]){
						x++;
						tt[aa[i]]=ee[aa[i]];
					}
				}
				else{
					if(tt[aa[i]]==ee[aa[i]]){
						x++;
						if(tt[aa[i]]=='T'){
							tt[aa[i]]='F';
						}
						else{
							tt[aa[i]]='T';
						}
					}
				}
			}

		}
			
	}

	ask(tt);
	
	





	return 0;
}