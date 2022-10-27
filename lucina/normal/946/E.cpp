#include<bits/stdc++.h>
using namespace std;
int t,f[11],n,cnt;
string s;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--){
        cin>>s;
        n=s.length();
        for(int i=0;i<10;i++)
            f[i]=0;
        for(int i=0;i<n;i++){
            f[s[i]-'0']++;
        }
        if((s[0]=='1'&&f[0]==n-1)||(s[0]=='1'&&s[n-1]=='1'&&f[0]==n-2)){
            for(int i=0;i<n-2;i++){
                cout<<'9';
            }
            cout<<'\n';
            continue;
        }
        bool r=true;
        for(int i=n-1;i>=0;i--){
        r=false;
          f[s[i]-'0']--;cnt=0;
            for(int k=0;k<10;k++)
                cnt+=(f[k]&1);
            for(int j=s[i]-'1';j>=0;j--){
            f[j]++;cnt+=(f[j]&1?1:-1);
            if(n-i-1>=cnt){
                s[i]=j+'0';
                for(int l=i+1;l<n-cnt;l++){
                    s[l]='9';
                }
                int l=n-cnt;
                for(int k=9;k>=0;k--){
                    if(f[k]&1){
                        s[l++]=k+'0';
                    }
                }
                r=true;
                break;
            }
            f[j]--;cnt+=(f[j]&1?1:-1);
          }
          if(r)break;
        }
        cout<<s<<'\n';
    }

}