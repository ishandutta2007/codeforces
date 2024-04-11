#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>

#define wait system("pause")
#define DB(x) cout << #x << "=" << x << endl

using namespace std;

typedef vector<int> vi;

int LEN;

vi lis(vi &M)
{
   vi L;
   vi ans;
   for (int i = 0; i < (int)M.size(); ++i)
   {
       int p = lower_bound(L.begin(), L.end(), M[i]) - L.begin();

       if (p == (int)L.size())
          L.push_back(M[i]);
       else
          L[p] = M[i];
          
       ans.push_back(p + 1);
   }
   
   LEN = L.size();
   
   return ans;
}

int SZ[(int)1e5 + 10];

int main()
{
    int tot = 0;
    int N; cin >> N;
    vi E;
    for (int i = 0; i < N; ++i)
    {
        int v; cin >> v;
        E.push_back(v);  
    }
    LEN = 0;
    vi left = lis(E);
    
    reverse(E.begin(), E.end());
    for (int i = 0; i < (int)E.size(); ++i)
        E[i] *= -1;
        
    vi right = lis(E);
    reverse(right.begin(), right.end());
        
    for (int i = 0; i < N; ++i)
    {
        if (left[i] + right[i] == LEN + 1)
           SZ[ left[i] ]++;
    }
    
    for (int i = 0; i < N; ++i)
    {
        if (left[i] + right[i] != LEN + 1)
           cout << 1;
        else if (SZ[ left[i] ] == 1)
           cout << 3;
        else
           cout << 2;
    }
    cout << endl;
    //wait;
}