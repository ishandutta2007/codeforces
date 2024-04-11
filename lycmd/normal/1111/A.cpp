#include<bits/stdc++.h>
using namespace std;
int check(char a){
    return a=='a'||a=='e'||a=='i'||a=='o'||a=='u';
}
string s,t;
int main(){
    ios::sync_with_stdio(0);
    cin>>s>>t;
    if(s.size()!=t.size())
        cout<<"No\n",exit(0);
    int n=s.size();
    for(int i=0;i<n;i++)
        if(check(s[i])!=check(t[i]))
            cout<<"No\n",exit(0);
    cout<<"Yes\n";
}