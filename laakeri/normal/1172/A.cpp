#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

int n;

int a[202020];
int b[202020];


int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  for (int i=0;i<n;i++){
    cin>>a[i];
  }
  for (int i=0;i<n;i++){
    cin>>b[i];
  }
  int f=-1;
  for (int i=0;i<n;i++){
    if (b[i]==1){
      f=i;
    }
  }
  if (f>=0){
    int ok=1;
    for (int i=f;i<n;i++){
      if (b[i]!=ok){
        ok=-1;
        break;
      } else if(i+1<n){
        ok++;
      }
    }
    if (ok>0){
      for (int i=0;i<n;i++){
        if (b[i]>0&&b[i]>ok){
          if (i>b[i]-ok-2){
            ok=-1;
            break;
          }
        }
      }
      if (ok>0){
        cout<<n-ok<<endl;
        return 0;
      }
    }
  }
  int ans=n;
  for (int i=0;i<n;i++){
    //cout<<i<<" "<<b[i]<<" "<<i+1 + (n-b[i])<<endl;
    if (b[i]>0) ans=max(ans, i+2 + (n-b[i]));
  }
  cout<<ans<<endl;
}