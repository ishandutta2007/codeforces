#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	string s; cin>>s;
	ll res=0;
	fore(i,0,SZ(s)){
		/*if(i+2<SZ(s)&&s[i]==s[i+1]&&s[i]==s[i+2])res+=min(10,SZ(s)-i-2);
		else if(i+4<SZ(s)&&s[i]==s[i+2]&&s[i]==s[i+4])res+=min(8,SZ(s)-i-4);
		else if(i+6<SZ(s)&&s[i]==s[i+3]&&s[i]==s[i+6])res+=min(6,SZ(s)-i-6);
		else if(i+8<SZ(s)&&s[i]==s[i+4]&&s[i]==s[i+8])res+=min(4,SZ(s)-i-8);
		else if(i+10<SZ(s)&&s[i]==s[i+5]&&s[i]==s[i+10])res+=min(2,SZ(s)-i-10);*/
		res+=max(0,SZ(s)-i-12);
	}
	set<ll> st;
	fore(i,0,SZ(s)){
		fore(j,1,6){
			if(i+2*j<SZ(s)&&s[i]==s[i+j]&&s[i]==s[i+2*j]){
				fore(ii,max(i-11+2*j,0),min(i+1,SZ(s))){
					fore(jj,max(0,i+2*j),min(i+12,SZ(s))){
						if(jj-ii<12){
							st.insert(300000*ii+jj);
						}
					}
				}
			}
		}
	}
	cout<<res+SZ(st);
	return 0;
}