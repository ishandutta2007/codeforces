#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

string s;

ll comp(ll v, ll m){
	if(v==0)return 0;
	return m-v;
}

ll sub(ll v, ll m){
	if(v-1<0)return v+m-1;
	return v-1;
}

ll add(ll v, ll m){
	if(v+1>=m)return 0;
	return v+1;
}

ll c[26];

ll gets(ll k){
	ll res=0;
	fore(i,0,26){
		res+=comp(c[i],k);
	}
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		cin>>s;
		if(n%k!=0){
			cout<<"-1\n";
			continue;
		}
		mset(c,0);
		for(auto i:s)c[i-'a']++;
		fore(i,0,26)c[i]=c[i]%k;
		if(gets(k)==0){
			cout<<s<<"\n";
			continue;
		}
		ll br=0;
		fore(i,0,n){
			//cout<<"i: "<<i<<"\n";
			c[s[n-1-i]-'a']=sub(c[s[n-1-i]-'a'],k);
			fore(j,s[n-1-i]-'a'+1,26){
				//cout<<" j: "<<j<<"\n";
				c[j]=add(c[j],k);
				if(gets(k)<=i){
					string res;
					fore(ii,0,n-1-i)res+=s[ii];
					res+=char('a'+j);
					string t;
					fore(ii,0,26){
						fore(_,0,comp(c[ii],k))t+=char('a'+ii);
					}
					while(SZ(res)+SZ(t)<n)res+='a';
					cout<<res+t<<"\n";
					br++;
					break;
				}
				c[j]=sub(c[j],k);
			}
			if(br)break;
		}
		assert(br);
	}
	
	return 0;
}