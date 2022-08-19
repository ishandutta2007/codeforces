#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
vector<ll> a(3);
for(ll& x : a) cin >> x;
cout << "First" << '\n' << flush;
ll f = ll(1e10);
cout << f << '\n' << flush;
int b;
cin >> b;
if(!b) exit(0);
a[b-1] += f;
ll g = 3 * a[b-1] - a[0] - a[1] - a[2];
cout << g << '\n' << flush;
int c;
cin >> c;
if(!c) exit(0);
a[c-1] += g;
ll h = a[c-1] - a[b-1];
cout << h << '\n' << flush;
int d;
cin >> d;
if(!d) exit(0);
}