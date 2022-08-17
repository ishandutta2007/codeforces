#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int max_n = 1000007;

string s;
ll n, kleft = 0, kright = 0;

ll rrnum[max_n]; //    
ll lrnum[max_n]; //    
vector<ll> sumlr; //         ,  
vector<ll> sumrl; //       ,  ,  


int main()
{
    cin >> n;
    cin >> s;
    for (int i = n - 1; i >= 0; i--)
    {
        s[i] = s[i] == 'U' ? 'R' : 'L';

        rrnum[i] = kright;
        lrnum[i] = kleft;

        if (s[i] == 'R')
        {
            kright++;
        }
        else
        {
            kleft++;
        }
    }

    ll sum = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == 'L')
        {
            sum += i + 1;
            sumlr.push_back(sum);
        }
    }
    sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'R')
        {
            sum += (n - i);
            sumrl.push_back(sum);
        }
    }

    reverse(sumlr.begin(), sumlr.end());
    reverse(sumrl.begin(), sumrl.end());

    sumlr.push_back(0);
    sumrl.push_back(0);

  //  for(int i = 0; i < sumlr.size(); i++) cout<<sumlr[i]<<' ';

 //   cout << endl;
  //  cout << s <<endl;

   // for(int i  = 0; i < n; i++) cout<<rrnum[i];

    for (int i = 0; i < n; ++i)
    {
        if (s[i] == 'R')
        {
            ll klr, krl, kll, krr; //  ,   

            klr = lrnum[i];
            kll = kleft - klr;
            krr = rrnum[i];
            krl = kright - krr - 1;
            char dir; //    
            if (krl >= klr) dir = 'R';
            else dir = 'L';
            if (dir == 'R')
            {
                ll distright = (sumlr[kll] - (i + 1) * klr) * 2;
                distright += (n - i); // 

                ll distleft = (sumrl[krr + 1] - sumrl[krr + 1 + klr] - (n - i) * klr) * 2;
                distleft += distright;
                cout << distleft << ' ';
            }
            else
            {
                ll distleft = (sumrl[krr + 1] - (n - i) * krl) * 2;
                distleft += (i + 1); // 

                ll distright = (sumlr[kll] - sumlr[kll + krl + 1] - (i + 1) * (krl + 1)) * 2;
                distleft += distright;
                cout << distleft << ' ';
            }
        }
        else
        {
            ll klr, krl, kll, krr; //  ,   

            klr = lrnum[i];
            kll = kleft - klr - 1;
            krr = rrnum[i];
            krl = kright - krr;

            char dir; //    
            if (krl > klr) dir = 'R';
            else dir = 'L';
            if (dir == 'R')
            {
                ll distright = (sumlr[kll + 1] - (i + 1) * klr) * 2;
                distright += (n - i);

                ll distleft = (sumrl[krr] - sumrl[krr + klr + 1] - (n - i) * (klr + 1)) * 2;
                distleft += distright;
                cout << distleft << ' ';
            }
            else
            {
                ll distleft = (sumrl[krr] - (n - i) * krl) * 2;
                distleft += (i + 1); // 

                ll distright = (sumlr[kll + 1] - sumlr[kll + krl + 1] - (i + 1) * krl) * 2;
                distleft += distright;
                cout << distleft << ' ';
            }
        }
    }

    return 0;
}