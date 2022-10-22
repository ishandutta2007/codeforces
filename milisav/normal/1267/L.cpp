#include<bits/stdc++.h>

using namespace std;

#define pb push_back
const int maxi = 2000;

string s;
int n, l, k;
string ans[maxi];
int main()
{
     cin>>n>>l>>k;
     cin>>s;

     sort(s.begin(), s.end());

     int same = k;
     int poz = 0;

     for (int i=1;i<=l;i++)
     {
         int val = same - 1;
         int nxt = 0;
         for (int j=poz;j<poz+same;j++){
            ans[k-val]+=s[j];
            val--;
            if (s[j] == s[poz + same - 1]) nxt++;
         }

         poz += same;
         same = nxt;
     }

     for (int i=1;i<=n;i++)
     {
         while(ans[i].size()<l){
            ans[i]+=s[poz];
            poz++;
         }
     }

     for (int i=1;i<=n;i++)
        cout<<ans[i]<<endl;

    return 0;
}