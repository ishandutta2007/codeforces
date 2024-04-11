#include<bits/stdc++.h>













using namespace std;
#define ll long long
#define ld double
const ll N = 998244353;
const ld MAX = 1000000010;
#define endl '\n'
ld sy, a, b;
vector<ld> starts;
vector<ld> en;
vector<ld> sums;

ld res(ld x, ld y)
{
    ld res = 0;
    int n = starts.size();
    ld l = a+(x-a)*(sy/(y+sy));
    ld r = b+(x-b)*(sy/(y+sy));

    auto k = lower_bound(en.begin(), en.end(), l)-en.begin();
    if (starts[k]<=l) {res-=(l-starts[k]);}
    auto t = lower_bound(starts.begin(), starts.end(), r) - starts.begin();
    if (en[t-1]>r) {res-=(en[t-1]-r);}
    res+=sums[t-1]-sums[k-1];
    res=res*(y+sy)/y;
        //cout<<l<<' '<<r<<' '<<k<<' '<<t<<endl;
    return res;


}

int main()
{
ios_base::sync_with_stdio(false);

cin>>sy>>a>>b;
sy = -sy;
int n;
cin>>n;
//ld temp1, temp2;
int temp1, temp2;
starts.push_back(-MAX);
en.push_back(1-MAX);
for (int i = 0; i<n; i++)
{
    cin>>temp1>>temp2; starts.push_back(temp1); en.push_back(temp2);
}
starts.push_back(MAX);
en.push_back(1+MAX);
sums.push_back(1);
for (int i = 1; i<starts.size(); i++) sums.push_back(sums[i-1]+en[i]-starts[i]);

int q;
cin>>q;
for (int i = 0; i<q; i++) {cin>>temp1>>temp2; cout<<setprecision(10)<<res(temp1, temp2)<<'\n';}




}