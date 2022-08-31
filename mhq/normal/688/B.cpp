#include <bits/stdc++.h>
using namespace std;

int n,m;

vector < pair < int, int > > g[100500];

int x,y,w,u;

long long d[100500];

int p[100500];

priority_queue < pair < long long, int > > nee;

int main() {
 //freopen("input.txt", "r", stdin);
 //freopen("output.txt","w",stdout);
 string s;
 cin>>s;
 cout<<s;
 for ( int i = 0; i < s.size(); i++) {
    cout<<s[s.size() - 1 - i];
 }
   return 0;
}