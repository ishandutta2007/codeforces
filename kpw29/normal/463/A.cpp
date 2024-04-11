#include <bits/stdc++.h>
using namespace std;
int s,n,i,j,k,l,m,w,e,r,y,u,o,p,z,x,c,v,h,b,q,a;
int t[101][3];
int main()
{
  ios_base::sync_with_stdio(false); 
  cin >> n >> s;
  w=100;
   for (i=1;i<=n;i++)
  {
    cin>> t[i][1];
    cin>> t[i][2];
    if (t[i][1]>s || (t[i][1] == s && t[i][2] > 0))
    {
        h++;
    }
  }
  if (h==n) cout<<"-1";
  else
    { 
        for (i=1;i<=n;i++)
        {   
            a=t[i][2];
            if (t[i][1] < s)
            {
                if (a != 0) w=min(w,a);
            }
    }

w=100-w;
cout<< w;
}}