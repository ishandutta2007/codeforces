#include <bits/stdc++.h>
typedef long long ll;

#define PB push_back
#define EB emplace_back 
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
	mipletsplay;
	ll n;
	pair <ll,ll> kek={0,INF},answer={-INF,INF},mem={-INF,INF};

	cin >>n;
	vector <ll> a(n);
	
    for (ll i=0;i<n;i++)
    {
      cin >> a[i];
      if (a[i]>=0) {
       a[i]= -a[i]-1; }
       if (answer.first<a[i]){
        answer.second=i;
        answer.first=a[i];
           
       }
       if (kek.first>a[i])
       {
         kek.second=i;
         kek.first=a[i];
           
       }
       
       if (mem.first<a[i] && (a[i]!=-1))
       {
         mem.second=i; 
         mem.first=a[i];
       }
 
    }
       
 
if (n%2==0)
{
  for (ll g=0;g<n;g++)
  cout << a[g]<< " ";
   
}
else
{ 
  if ((a[answer.second]!=-1))
  {
    a[kek.second]= -a[kek.second]-1;
    for (ll q=0;q<n;q++)
    cout << a[q]<< " ";  
      
  }
  else{
  if (a[kek.second]==-1)
  {
   for (ll u=0;u<n;u++)   
    cout << 0 << " "; 
      
      
  }
  else
  { if (mem.second==-2) {
    a[kek.second]=-a[kek.second]-1;  
    for (ll o=0;o<n;o++)
    cout << a[o]<< " "; } 
    else{
      a[kek.second]=-a[kek.second]-1;  
    for (ll o=0;o<n;o++)
    cout << a[o]<< " ";  
        
        
        
    } 
   
   
   
   
      
  }
      
      
      
  }
  
    
}
}