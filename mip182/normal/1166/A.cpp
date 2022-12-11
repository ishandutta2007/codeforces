#include <iostream>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <bitset>
#include <queue>
#include <stack>
#include <deque>
#include <time.h>
#include <complex>
typedef long long ll;
#define gcd(x,y) __builtin_gcd(x,y)
#define numberof1(x) __builtin_popcount(x)
#define povsemelementam(i,mnozh) for(auto i: mnozh)
#define podotrezok(i,j) substr(i-1,j) // like prefix sum, (i,j)=s[j]-s[i-1]
#define pb push_back
#define pf push_front
#define popf pop_front
#define popb pop_back
#define eb emplace_back 
#define MP make_pair 
#define F first
#define S second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector <int>
#define vll vector <ll>
#define mipletsplay ios_base::sync_with_stdio(0); cin.tie(0); 
#define REP(i, a, b) for (int i = a; i < b; i++)
 
 
using namespace std;
const ll INFLL = 1e18;
const int MAXN = 3e5;
const int INF = 1e9;
 
int main() {
    map <int,int> m;
    int n;
    cin >> n;
    for (int i=0;i<n;i++)
    {
       string s;
       cin >> s;
       m[(int)(s[0])]++;
        
    }
    ll answer=0;
    for (auto k:m)
    {
     if (k.second%2==0)   
    answer+=(k.second/2)*(k.second/2 -1);
    else {
    
    ll j=k.second;
    answer+=((j/2)*(j/2 -1))/2 + ((j/2 +1)*(j/2))/2;
        
        
        
    }
    }
    cout << answer;
    }