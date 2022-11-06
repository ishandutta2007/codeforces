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
        ll n,k; cin>>n>>k;
        string s; cin>>s;
        if(n==1){
            if(k==0){
                cout<<s;
            }else{
                cout<<"0";
            }
            return 0;
        }
        fore(i,0,n){
            if(k==0)break;
            if(i==0){
                if(s[i]!='1'){
                    k--; s[i]='1';
                }
            }else{
                if(s[i]!='0'){
                    k--; s[i]='0';
                }
            }
        }
        cout<<s;
    	return 0;
    }