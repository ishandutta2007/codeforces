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

const ll MAXN=100005;
int d1[MAXN];//d1[i] = max odd palindrome centered on i
int d2[MAXN];//d2[i] = max even palindrome centered on i
//s  aabbaacaabbaa
//d1 1111117111111
//d2 0103010010301
void manacher(string& s){
	int l=0,r=-1,n=s.size();
	fore(i,0,n){
		int k=i>r?1:min(d1[l+r-i],r-i);
		while(i+k<n&&i-k>=0&&s[i+k]==s[i-k])k++;
		d1[i]=k--;
		if(i+k>r)l=i-k,r=i+k;
	}
	l=0;r=-1;
	fore(i,0,n){
		int k=i>r?0:min(d2[l+r-i+1],r-i+1);k++;
		while(i+k<=n&&i-k>=0&&s[i+k-1]==s[i-k])k++;
		d2[i]=--k;
		if(i+k-1>r)l=i-k,r=i+k-1;
	}
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		string s; cin>>s;
		ll maxi=0;
		pair<ll,ll> maxid={0,0};
		ll tp=0;
		manacher(s);
		fore(i,0,SZ(s)+1){
			fore(j,0,SZ(s)+1-i){
				if((j>0&&i>=j&&s[SZ(s)-j]==s[j-1])||j==0){
					if(i>j){
						if((j+i)%2==1){
							if(2*d1[(i-j)/2+j]-1>=i-j){
								if(maxi<i+j){
									maxi=i+j;
									maxid={i,j};
									//if(i+j==SZ(s))cout<<i<<" "<<j<<"\n";
								}
							}
						}else{
							if(2*d2[(i-j)/2+j]>=i-j){
								if(maxi<i+j){
									maxi=i+j;
									maxid={i,j};
									//if(i+j==SZ(s))cout<<i<<" "<<j<<"\n";
								}
							}
						}
					}else if(i==j){
						if(maxi<i+j){
							maxi=i+j;
							maxid={i,j};
						}
					}
				}else break;
			}
		}
		reverse(ALL(s));
		manacher(s);
		fore(i,0,SZ(s)+1){
			fore(j,0,SZ(s)+1-i){
				if((j>0&&i>=j&&s[SZ(s)-j]==s[j-1])||j==0){
					if(i>j){
						if((j+i)%2==1){
							if(2*d1[(i-j)/2+j]-1>=i-j){
								if(maxi<i+j){
									maxi=i+j;
									maxid={i,j};
									tp=1;
									//if(i+j==SZ(s))cout<<j<<" "<<i<<"\n";
								}
							}
						}else{
							if(2*d2[(i-j)/2+j]>=i-j){
								if(maxi<i+j){
									maxi=i+j;
									maxid={i,j};
									tp=1;
									//if(i+j==SZ(s))cout<<j<<" "<<i<<"\n";
								}
							}
						}
					}else if(i==j){
						if(maxi<i+j){
							maxi=i+j;
							maxid={i,j};
							tp=1;
						}
					}
				}else break;
			}
		}
		if(tp==0)reverse(ALL(s));
		//else swap(maxid.fst,maxid.snd);
		//cout<<maxid.fst<<" "<<maxid.snd<<"\n";
		string res;
		fore(i,0,maxid.fst)res+=s[i];
		fore(i,0,maxid.snd)res+=s[SZ(s)-maxid.snd+i];
		cout<<res<<"\n";
	}
	
	return 0;
}