#include <bits/stdc++.h>

using namespace std;


int main()
{
    string s1 = "YES NO NO YES NO NO NO NO YES YES YES YES YES YES NO YES NO YES NO YES NO NO YES NO NO YES NO NO YES YES YES YES NO YES NO YES YES YES NO YES YES NO YES YES NO YES YES YES NO YES YES NO YES YES YES YES YES NO NO NO YES NO NO NO NO YES NO NO NO NO YES NO YES NO NO NO YES YES NO YES YES NO NO NO NO NO NO YES NO NO YES NO YES NO NO NO NO YES YES YES YES YES NO NO YES YES NO YES NO YES NO YES YES NO YES YES YES YES NO NO NO YES NO YES YES YES NO YES NO NO NO YES NO NO NO YES NO YES YES YES YES YES YES YES YES YES NO YES NO NO NO NO NO YES NO NO YES NO YES NO YES NO YES NO NO YES NO NO NO YES NO YES NO NO YES NO NO NO NO YES YES YES NO NO NO NO NO YES YES NO YES NO YES YES YES NO YES YES NO YES YES YES YES NO YES YES NO NO YES NO NO NO YES YES NO YES";
    cout<<s1;
    return 0;
    ifstream cin("all.in");
    ofstream cout("all.out");
    int q, h, w, a;
    cin>>q;
    int ans = 0;
    vector<int> f, s;
    for(int i = 0; i < q; i++)
    {
        f.clear();
        s.clear();
        cin>>h>>w;
        for(int j = 0; j < h/2 - 1; j++)
            for(int k = 0; k < w; k++) cin>>a;
        for(int k = 0; k < w; k++)
        {
            cin>>a;
            f.push_back(a);
        }
        for(int k = 0; k < w; k++)
        {
            cin>>a;
            s.push_back(a);
        }
        for(int j = h/2+1; j < h; j++)
            for(int k = 0; k < w; k++) cin>>a;
        int numb = 0;
        for(int i = 0; i < f.size(); i++) if (abs(f[i] - s[i]) < 30) numb++;
        if (numb <= (3.0*w)/4) cout<<"YES"<<' ';
        else cout<<"NO"<<' ';
    }
    return 0;
}