#include <bits/stdc++.h>
using namespace std;
int main(){
    int N,cnt=0;
    cin>>N;
    string s;
    cin>>s;
    for(int i=0;i<N-1;i++)if(s[i]==s[i+1])cnt++;
    cout<<cnt<<"\n";
}