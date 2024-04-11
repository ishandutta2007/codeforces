#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool chmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool chmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int m,n,t_case;
string s;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		cin>>n>>s;
		bool flag=false;
		for(char i='a';i<='z';++i)
			if(s.find(i)==-1){
				cout<<i<<endl;
				flag=true;
				break;
			}
		if(!flag)
			for(char j='a';j<='z';++j){
				string t1="";
				t1+=j;
				if(flag)break;
				for(char i='a';i<='z';++i){
					string t2=t1+i;
					if(s.find(t2)==-1){
						cout<<t2<<endl;
						flag=true;
						break;
					}
				}
			}
		if(!flag)
			for(char k='a';k<='z';++k){
				string t1="";
				t1+=k;
				if(flag)break;
				for(char j='a';j<='z';++j){
					string t2=t1+j;
					if(flag)break;
					for(char i='a';i<='z';++i){
						string t3=t2+i;
						if(s.find(t3)==-1){
							cout<<t3<<endl;
							flag=true;
							break;
						}
					}
				}
			}
	}
	return 0;
}