#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i,n) for(int i=0; i<(n); i++)

void loop(){
 int N; cin>>N;
 string S; cin>>S;
 rep(i,N) cout<<S[i*2];
 cout<<endl;
}

int main() {
 int T; scanf("%d",&T);
 while(T--) loop();
 return 0;
}