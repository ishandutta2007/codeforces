#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define push_back pb
const ll INF=1e9;
const ll INFLL=1e18;
int main() {
ios_base::sync_with_stdio(0);
cin.tie();
vector <int> a(4);
for (int i=0;i<4;i++)
cin>>a[i];
sort(a.begin(),a.end());
if (a[0]+a[3]==a[1]+a[2] || a[0]+a[1]+a[2]==a[3])
cout<<"YES";
else
cout<<"NO";
    
    
}