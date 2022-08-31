#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define mp make_pair

void print(vector<auto> &a)
{
    for (int i = 0; i<a.size(); i++) cout<<a[i]<<' ';
    cout<<endl;
}

void get(vector<auto> &a)
{
    for (int i = 0; i<a.size(); i++) cin>>a[i];
}

ll p = 1e9 + 7;

ll mul(ll a, ll b) {
    return (1LL * a%p * b%p) % p;
}

ll add(ll a, ll b) {
    ll s = (a+b);
    s = s%p;
    if (s<0) s+=p; 
    return s;
}

int po(int a, int deg)
{
    if (deg==0) return 1;
    if (deg%2==1) return mul(a, po(a, deg-1));
    int t = po(a, deg/2);
    return mul(t, t);
}

int inv(int n)
{
    return po(n, p-2);
}

mt19937 rnd(228);




int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int xp, yp, xv, yv;
    cin>>xp>>yp>>xv>>yv;
    if (xp+yp<=max(xv, yv)) {cout<<"Polycarp"; return 0;}
    if (xp<=xv&&yp<=yv) {cout<<"Polycarp"; return 0;}
     else cout<<"Vasiliy";

}