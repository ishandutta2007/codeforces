#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
char s[5],a[5];
int main(){
cin>>s;
for(int i=0;i<5;i++){
    cin>>a;
    if(a[0]==s[0]||a[1]==s[1]){
        cout<<"YES";
        return 0;
    }
}
cout<<"NO";



}