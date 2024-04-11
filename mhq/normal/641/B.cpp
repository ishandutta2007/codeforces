#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define mp make_pair

void print(auto &a)
{
    for (auto s: a) cout<<s<<' ';
    cout<<endl;
}

void get(vector<auto> &a)
{
    for (int i = 0; i<a.size(); i++) cin>>a[i];
}

int p = 10007;


int mul(int a, int b) {
    return (1LL * a%p * b%p) % p;
}

int add(int a, int b) {
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

int n, m;

vector<vector<int>> A;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin>>n>>m;
    A = vector<vector<int>> (n, vector<int>(m));
    int q;
    cin>>q;
    vector<vector<int>> op;
    int t, x, a, b;
    for (int i = 0; i<q; i++)
    {
        cin>>t; 
        if (t!=3) {cin>>x; x--; op.push_back({t, x});}
        else {cin>>x>>a>>b; x--; a--; op.push_back({t, x, a, b});}
    }
    
    for (int i = q-1; i>=0; i--)
    {
        if (op[i][0]==3) A[op[i][1]][op[i][2]] = op[i][3];
        if (op[i][0]==1) 
        {
            vector<int> temp(m);
            for (int j = 0; j<m; j++) temp[j] = A[op[i][1]][j];
            for (int j = 0; j<m; j++) A[op[i][1]][j] = temp[(j-1+m)%m];
        }
        if (op[i][0]==2)
        {
            vector<int> temp(n);
            for (int j = 0; j<n; j++) temp[j] = A[j][op[i][1]];
            for (int j = 0; j<n; j++) A[j][op[i][1]] = temp[(j-1+n)%n];
        }
    }
    
        for (int i = 0; i<n; i++) print(A[i]);

}