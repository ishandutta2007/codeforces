#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int a=0,b=s.length()-1;
        for(int i=b;i>-1;i--){
            if(s[b]=='a'+i)b--;
            else if(s[a]=='a'+i)a++;
            else{
                cout<<"NO\n";
                goto fuck;
            }
        }
        cout<<"YES\n";
        fuck:;
    }
}