#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n;
string a,b;
int pi[1000010];
int prefix_function(const string &s) {
    int n = (int)s.length();
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi[n-1];
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>b;
        if(i>1){
            int tt=(int)b.size();
            b+='#';
            int r=(int)a.size()-1;
            for(int j=min((int)a.size(),tt);j>=0;j--){
                b.push_back(a[r-j]);
            }
            int x=prefix_function(b);
            for(int j=x;j<tt;j++){
                a.push_back(b[j]);
            }
        }
        else{
            a=b;
        }
    }
    cout<<a<<'\n';
}
/*
    Good Luck
        -Lucina
*/