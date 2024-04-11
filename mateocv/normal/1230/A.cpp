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
        
     
        int main(){FIN;
            ll a[4],s=0;
            fore(i,0,4)cin>>a[i],s+=a[i];
            if(s%2==1){
                cout<<"NO"; return 0;
            }else{
                fore(i,0,4){
                    if(s/2==a[i]){
                        cout<<"YES"; return 0;
                    }
                }
                fore(i,0,4){
                    fore(j,i+1,4){
                        if(a[i]+a[j]==s/2){
                             cout<<"YES"; return 0; 
                        }
                    }
                }
            }
            cout<<"NO";
        	return 0;
        }