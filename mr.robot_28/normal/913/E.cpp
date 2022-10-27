#include<bits/stdc++.h>
using namespace std;
bool cmp(string a, string b)
{
    if(b == "")
    {
        return true;
    }
    if(a == "")
    {
        return false;
    }
    if(a.size() < b.size())
    {
        return true;
    }
    if(a.size() > b.size())
    {
        return 0;
    }
    return a < b;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 //   ofstream cout("output.txt");
    int t;
    cin >> t;
     /*  string dp[1 << 8][2];
        for(int mask = 0; mask < (1 << 8); mask++)
        {
            for(int t = 0; t < 2; t++)
            {
                dp[mask][t] = "";
            }
        }
        set <pair<string, pair <int, int> > > q;
        for(int i = 0; i < 3; i++)
        {
            char t = 'x' + i;
            string s1 = "";
            s1 += t;
            string s2 = "!";
            s2 += t;
            int mask1 = 0;
            for(int j = 0; j < 8; j++)
            {
                if(j & (1 << (2 - i)))
                {
                    mask1 += (1 << j);
                }
            }
            int mask2 = (1 << 8) - 1 -mask1;
            if(cmp(s1, dp[mask1][1]))
            {
                dp[mask1][1] = s1;
            }
            if(cmp(s2, dp[mask2][1]))
            {
                dp[mask2][1] = s2;
            }
            q.insert({s1, {mask1, 1}});
            q.insert({s2, {mask2, 1}});
        }
        while(q.size() > 0)
        {
            int mask = q.begin() -> second.first;
            string s1 = q.begin() -> first;
            int type = q.begin() -> second.second;
            q.erase(*q.begin());
     //       cout << mask << " " << s1 << "\n";
            for(int i = 0; i < (1 << 8); i++)
            {
                for(int t = 0;t < 2; t++)
                {
                    if(dp[i][t] == "")
                    {
                        continue;
                    }
                    string s2 = dp[i][t] + '|' + dp[mask][type];
                    string s3 = dp[mask][type] + '|' + dp[i][t];
                    if(cmp(s3, s2))
                    {
                        swap(s2, s3);
                    }
                    if(cmp(s2, dp[i | mask][0]))
                    {
                        q.erase({dp[i | mask][0], {(i | mask), 0}});
                        dp[i | mask][0] = s2;
                        q.insert({dp[i | mask][0], {(i | mask), 0}});
                    }
                }
            }
            if(type == 1)
            {
                string s2, s3;
                for(int i = 0; i < (1 << 8); i++)
                {
                    if(dp[i][1] == "")
                    {
                        continue;
                    }
                    s2 = s1 + "&" + dp[i][1];
                    s3 = dp[i][1] + "&" + s1;
                    if(cmp(s3, s2))
                    {
                        swap(s2, s3);
                    }
                    if(cmp(s2, dp[i & mask][1]))
                    {
                        q.erase({dp[i & mask][1], {(i & mask), 1}});
                        dp[i & mask][1] = s2;
                        q.insert({s2, {i & mask, 1}});
                    }
                }
            }
            string s2 = "";
            if(type == 0)
            {
                s2 += "(";
                s2 += dp[mask][type];
                s2 += ")";
                if(cmp(s2, dp[mask][1]))
                {
                q.erase({dp[mask][1], {mask, 1}});
                dp[mask][1] = s2;
                q.insert({dp[mask][1], {mask, 1}});
                }
            }
                s2 = "!";
                s2 += "(";
                s2 += dp[mask][type];
                s2 += ")";
                int mask_to = (1 << 8) - 1 - mask;
                if(cmp(s2, dp[mask_to][1]))
                {

                q.erase({dp[mask_to][1], {mask_to, 1}});
                dp[mask_to][1] = s2;
                q.insert({dp[mask_to][1], {mask_to, 1}});
                }
        }
        for(int mask = 0; mask < (1 << 8); mask++)
        {
            for(int t = 0; t < 2; t++)
            {
                char w = '"';
                dp[mask][t] = w + dp[mask][t] + w;
                cout << dp[mask][t] << ", ";
            }
            cout << "\n";
        }*/
    vector <string> dp = {"!x&x|!x&x", "!x&x",
"!(x|y|z)|!x&x", "!(x|y|z)",
"!x&!y&z|!x&x", "!x&!y&z",
"!x&!y|!x&x", "!x&!y",
"!x&!z&y|!x&x", "!x&!z&y",
"!x&!z|!x&x", "!x&!z",
"!x&!y&z|!x&!z&y", "!(!y&!z|x|y&z)",
"!x&!y|!x&!z", "!(x|y&z)",
"!x&x|!x&y&z", "!x&y&z",
"!(x|y|z)|!x&y&z", "!(!y&z|!z&y|x)",
"!x&x|!x&z", "!x&z",
"!x&!y|!x&z", "!(!z&y|x)",
"!x&x|!x&y", "!x&y",
"!x&!z|!x&y", "!(!y&z|x)",
"!x&y|!x&z", "!x&(y|z)",
"!x|!x", "!x",
"!x&x|!y&!z&x", "!y&!z&x",
"!x&x|!y&!z", "!y&!z",
"!x&!y&z|!y&!z&x", "!(!x&!z|x&z|y)",
"!x&!y|!y&!z", "!(x&z|y)",
"!x&!z&y|!y&!z&x", "!(!x&!y|x&y|z)",
"!x&!z|!y&!z", "!(x&y|z)",
"!(!x&!y|x&y|z)|!x&!y&z", "!((x|y)&z|x&y)&(x|y|z)",
"!(x&y|z)|!x&!y", "!((x|y)&z|x&y)",
"!x&y&z|!y&!z&x", "(!x&y&z|!y&!z&x)",
"!x&y&z|!y&!z", "(!x&y&z|!y&!z)",
"!x&z|!y&!z&x", "(!x&z|!y&!z&x)",
"!x&z|!y&!z", "!(!z&y|x&z)",
"!x&y|!y&!z&x", "(!x&y|!y&!z&x)",
"!x&y|!y&!z", "!(!y&z|x&y)",
"!x&(y|z)|!y&!z&x", "!((y|z)&x)&(x|y|z)",
"!x|!y&!z", "!((y|z)&x)",
"!x&x|!y&x&z", "!y&x&z",
"!(x|y|z)|!y&x&z", "!(!x&z|!z&x|y)",
"!x&x|!y&z", "!y&z",
"!x&!y|!y&z", "!(!z&x|y)",
"!x&!z&y|!y&x&z", "(!x&!z&y|!y&x&z)",
"!x&!z|!y&x&z", "(!x&!z|!y&x&z)",
"!x&!z&y|!y&z", "(!x&!z&y|!y&z)",
"!x&!z|!y&z", "!(!z&x|y&z)",
"!x&y&z|!y&x&z", "(!x&y|!y&x)&z",
"!(!x&z|!z&x|y)|!x&y&z", "!(!x&!y&z|!z&(x|y)|x&y)",
"!x&z|!y&z", "!(x&y)&z",
"!(!z&x|y)|!x&z", "!(!z&(x|y)|x&y)",
"!x&y|!y&x&z", "(!x&y|!y&x&z)",
"!(!y&z|x)|!y&x&z", "(!(!y&z|x)|!y&x&z)",
"!x&y|!y&z", "(!x&y|!y&z)",
"!x|!y&z", "(!x|!y&z)",
"!x&x|!y&x", "!y&x",
"!y&!z|!y&x", "!(!x&z|y)",
"!y&x|!y&z", "!y&(x|z)",
"!y|!y", "!y",
"!x&!z&y|!y&x", "(!x&!z&y|!y&x)",
"!x&!z|!y&x", "!(!x&z|x&y)",
"!x&!z&y|!y&(x|z)", "!((x|z)&y)&(x|y|z)",
"!x&!z|!y", "!((x|z)&y)",
"!x&y&z|!y&x", "(!x&y&z|!y&x)",
"!(!x&z|y)|!x&y&z", "(!(!x&z|y)|!x&y&z)",
"!x&z|!y&x", "(!x&z|!y&x)",
"!x&z|!y", "(!x&z|!y)",
"!x&y|!y&x", "(!x&y|!y&x)",
"!(!x&z|y)|!x&y", "!(!x&!y&z|x&y)",
"!x&(y|z)|!y&x", "!(x&y)&(x|y|z)",
"!x|!y", "!(x&y)",
"!x&x|!z&x&y", "!z&x&y",
"!(x|y|z)|!z&x&y", "!(!x&y|!y&x|z)",
"!x&!y&z|!z&x&y", "(!x&!y&z|!z&x&y)",
"!x&!y|!z&x&y", "(!x&!y|!z&x&y)",
"!x&x|!z&y", "!z&y",
"!x&!z|!z&y", "!(!y&x|z)",
"!x&!y&z|!z&y", "(!x&!y&z|!z&y)",
"!x&!y|!z&y", "!(!y&x|y&z)",
"!x&y&z|!z&x&y", "(!x&z|!z&x)&y",
"!(!x&y|!y&x|z)|!x&y&z", "!(!x&!z&y|!y&(x|z)|x&z)",
"!x&z|!z&x&y", "(!x&z|!z&x&y)",
"!(!z&y|x)|!z&x&y", "(!(!z&y|x)|!z&x&y)",
"!x&y|!z&y", "!(x&z)&y",
"!(!y&x|z)|!x&y", "!(!y&(x|z)|x&z)",
"!x&z|!z&y", "(!x&z|!z&y)",
"!x|!z&y", "(!x|!z&y)",
"!x&x|!z&x", "!z&x",
"!y&!z|!z&x", "!(!x&y|z)",
"!x&!y&z|!z&x", "(!x&!y&z|!z&x)",
"!x&!y|!z&x", "!(!x&y|x&z)",
"!z&x|!z&y", "!z&(x|y)",
"!z|!z", "!z",
"!x&!y&z|!z&(x|y)", "!((x|y)&z)&(x|y|z)",
"!x&!y|!z", "!((x|y)&z)",
"!x&y&z|!z&x", "(!x&y&z|!z&x)",
"!(!x&y|z)|!x&y&z", "(!(!x&y|z)|!x&y&z)",
"!x&z|!z&x", "(!x&z|!z&x)",
"!(!x&y|z)|!x&z", "!(!x&!z&y|x&z)",
"!x&y|!z&x", "(!x&y|!z&x)",
"!x&y|!z", "(!x&y|!z)",
"!x&(y|z)|!z&x", "!(x&z)&(x|y|z)",
"!x|!z", "!(x&z)",
"!y&x&z|!z&x&y", "(!y&z|!z&y)&x",
"!(!x&y|!y&x|z)|!y&x&z", "!(!x&(y|z)|!y&!z&x|y&z)",
"!y&z|!z&x&y", "(!y&z|!z&x&y)",
"!(!z&x|y)|!z&x&y", "(!(!z&x|y)|!z&x&y)",
"!y&x&z|!z&y", "(!y&x&z|!z&y)",
"!(!y&x|z)|!y&x&z", "(!(!y&x|z)|!y&x&z)",
"!y&z|!z&y", "(!y&z|!z&y)",
"!(!y&x|z)|!y&z", "!(!y&!z&x|y&z)",
"!x&y&z|!y&x&z|!z&x&y", "!(!x&!y|x&y&z)&(x&y|z)",
"!(!x&y|!y&x|z)|!x&y&z|!y&x&z", "(!x&!y|x&y|z)&(!x&y|!y&x|!z)",
"!(x&y)&z|!z&x&y", "!(x&y&z)&(x&y|z)",
"!(!z&x|y)|!x&z|!z&x&y", "!(x&y&z)&(!x&!y|x&y|z)",
"!(x&z)&y|!y&x&z", "!(x&y&z)&(x&z|y)",
"!(!y&x|z)|!x&y|!y&x&z", "!(x&y&z)&(!x&!z|x&z|y)",
"!(x&y)&z|!z&y", "!(!y&!z|x&y&z)",
"!x|!y&z|!z&y", "(!x|!y&z|!z&y)",
"!y&x|!z&x", "!(y&z)&x",
"!(!x&y|z)|!y&x", "!(!x&(y|z)|y&z)",
"!y&z|!z&x", "(!y&z|!z&x)",
"!y|!z&x", "(!y|!z&x)",
"!y&x|!z&y", "(!y&x|!z&y)",
"!y&x|!z", "(!y&x|!z)",
"!y&(x|z)|!z&y", "!(y&z)&(x|y|z)",
"!y|!z", "!(y&z)",
"!(y&z)&x|!x&y&z", "!(x&y&z)&(x|y&z)",
"!(!x&y|z)|!x&y&z|!y&x", "!(x&y&z)&(!y&!z|x|y&z)",
"!(x&y)&z|!z&x", "!(!x&!z|x&y&z)",
"!x&z|!y|!z&x", "(!x&z|!y|!z&x)",
"!(x&z)&y|!y&x", "!(!x&!y|x&y&z)",
"!x&y|!y&x|!z", "(!x&y|!y&x|!z)",
"!x&y|!y&z|!z&x", "!(x&y&z)&(x|y|z)",
"!x|!y|!z", "!(x&y&z)",
"!x&x|x&y&z", "x&y&z",
"!(x|y|z)|x&y&z", "(!(x|y|z)|x&y&z)",
"!x&!y&z|x&y&z", "(!x&!y|x&y)&z",
"!x&!y|x&y&z", "(!x&!y|x&y&z)",
"!x&!z&y|x&y&z", "(!x&!z|x&z)&y",
"!x&!z|x&y&z", "(!x&!z|x&y&z)",
"!(!y&!z|x|y&z)|x&y&z", "(!(!y&!z|x|y&z)|x&y&z)",
"!(x|y&z)|x&y&z", "(!(x|y&z)|x&y&z)",
"y&z|y&z", "y&z",
"!(x|y|z)|y&z", "(!(x|y|z)|y&z)",
"!x&z|y&z", "(!x|y)&z",
"!x&!y|y&z", "(!x&!y|y&z)",
"!x&y|y&z", "(!x|z)&y",
"!x&!z|y&z", "(!x&!z|y&z)",
"!x&(y|z)|y&z", "(!x&(y|z)|y&z)",
"!x|y&z", "(!x|y&z)",
"!y&!z&x|x&y&z", "(!y&!z|y&z)&x",
"!y&!z|x&y&z", "(!y&!z|x&y&z)",
"!(!x&!z|x&z|y)|x&y&z", "(!(!x&!z|x&z|y)|x&y&z)",
"!(x&z|y)|x&y&z", "(!(x&z|y)|x&y&z)",
"!(!x&!y|x&y|z)|x&y&z", "(!(!x&!y|x&y|z)|x&y&z)",
"!(x&y|z)|x&y&z", "(!(x&y|z)|x&y&z)",
"!(!x&!y|x&y|z)|!x&!y&z|x&y&z", "(!x&!y|!z|x&y)&(!x&y|!y&x|z)",
"!((x|y)&z|x&y)|x&y&z", "(!((x|y)&z|x&y)|x&y&z)",
"!y&!z&x|y&z", "(!y&!z&x|y&z)",
"!y&!z|y&z", "(!y&!z|y&z)",
"!x&z|!y&!z&x|y&z", "!(!y&x&z)&(!y&x|z)",
"!(x&z|y)|y&z", "!(!y&x&z|!z&y)",
"!x&y|!y&!z&x|y&z", "!(!z&x&y)&(!z&x|y)",
"!(x&y|z)|y&z", "!(!y&z|!z&x&y)",
"!x&(y|z)|!y&!z&x|y&z", "(!x&(y|z)|!y&!z&x|y&z)",
"!x|!y&!z|y&z", "(!x|!y&!z|y&z)",
"x&z|x&z", "x&z",
"!(x|y|z)|x&z", "(!(x|y|z)|x&z)",
"!y&z|x&z", "(!y|x)&z",
"!x&!y|x&z", "(!x&!y|x&z)",
"!x&!z&y|x&z", "(!x&!z&y|x&z)",
"!x&!z|x&z", "(!x&!z|x&z)",
"!x&!z&y|!y&z|x&z", "!(!x&y&z)&(!x&y|z)",
"!(x|y&z)|x&z", "!(!x&y&z|!z&x)",
"x&z|y&z", "(x|y)&z",
"!(x|y|z)|(x|y)&z", "(!(x|y|z)|(x|y)&z)",
"z|z", "z",
"!x&!y|z", "(!x&!y|z)",
"!x&y|x&z", "(!x&y|x&z)",
"!(!y&z|x)|x&z", "!(!x&!y&z|!z&x)",
"!x&y|z", "(!x&y|z)",
"!x|z", "(!x|z)",
"!y&x|x&z", "(!y|z)&x",
"!y&!z|x&z", "(!y&!z|x&z)",
"!y&(x|z)|x&z", "(!y&(x|z)|x&z)",
"!y|x&z", "(!y|x&z)",
"!x&!z&y|!y&x|x&z", "!(!z&x&y)&(!z&y|x)",
"!(x&y|z)|x&z", "!(!x&z|!z&x&y)",
"!x&!z&y|!y&(x|z)|x&z", "(!x&!z&y|!y&(x|z)|x&z)",
"!x&!z|!y|x&z", "(!x&!z|!y|x&z)",
"!y&x|y&z", "(!y&x|y&z)",
"!(!x&z|y)|y&z", "!(!x&!y&z|!z&y)",
"!y&x|z", "(!y&x|z)",
"!y|z", "(!y|z)",
"!x&y|!y&x|x&z", "!(!x&!y|!z&x&y)",
"!x&!z|!y&x|y&z", "(!x&!z|!y&x|y&z)",
"!x&y|!y&x|z", "(!x&y|!y&x|z)",
"!x|!y|z", "!(!z&x&y)",
"x&y|x&y", "x&y",
"!(x|y|z)|x&y", "(!(x|y|z)|x&y)",
"!x&!y&z|x&y", "(!x&!y&z|x&y)",
"!x&!y|x&y", "(!x&!y|x&y)",
"!z&y|x&y", "(!z|x)&y",
"!x&!z|x&y", "(!x&!z|x&y)",
"!x&!y&z|!z&y|x&y", "!(!x&y&z)&(!x&z|y)",
"!(x|y&z)|x&y", "!(!x&y&z|!y&x)",
"x&y|y&z", "(x|z)&y",
"!(x|y|z)|(x|z)&y", "(!(x|y|z)|(x|z)&y)",
"!x&z|x&y", "(!x&z|x&y)",
"!(!z&y|x)|x&y", "!(!x&!z&y|!y&x)",
"y|y", "y",
"!x&!z|y", "(!x&!z|y)",
"!x&z|y", "(!x&z|y)",
"!x|y", "(!x|y)",
"!z&x|x&y", "(!z|y)&x",
"!y&!z|x&y", "(!y&!z|x&y)",
"!x&!y&z|!z&x|x&y", "!(!y&x&z)&(!y&z|x)",
"!(x&z|y)|x&y", "!(!x&y|!y&x&z)",
"!z&(x|y)|x&y", "(!z&(x|y)|x&y)",
"!z|x&y", "(!z|x&y)",
"!x&!y&z|!z&(x|y)|x&y", "(!x&!y&z|!z&(x|y)|x&y)",
"!x&!y|!z|x&y", "(!x&!y|!z|x&y)",
"!z&x|y&z", "(!z&x|y&z)",
"!(!x&y|z)|y&z", "!(!x&!z&y|!y&z)",
"!x&z|!z&x|x&y", "!(!x&!z|!y&x&z)",
"!x&!y|!z&x|y&z", "(!x&!y|!z&x|y&z)",
"!z&x|y", "(!z&x|y)",
"!z|y", "(!z|y)",
"!x&z|!z&x|y", "(!x&z|!z&x|y)",
"!x|!z|y", "!(!y&x&z)",
"x&y|x&z", "(y|z)&x",
"!(x|y|z)|(y|z)&x", "(!(x|y|z)|(y|z)&x)",
"!y&z|x&y", "(!y&z|x&y)",
"!(!z&x|y)|x&y", "!(!x&y|!y&!z&x)",
"!z&y|x&z", "(!z&y|x&z)",
"!(!y&x|z)|x&z", "!(!x&z|!y&!z&x)",
"!y&z|!z&y|x&y", "!(!x&y&z)&(y|z)",
"!x&!y|!z&y|x&z", "(!x&!y|!z&y|x&z)",
"(x|y)&z|x&y", "((x|y)&z|x&y)",
"!(x|y|z)|(x|y)&z|x&y", "(!(x|y|z)|(x|y)&z|x&y)",
"x&y|z", "(x&y|z)",
"!x&!y|x&y|z", "(!x&!y|x&y|z)",
"x&z|y", "(x&z|y)",
"!x&!z|x&z|y", "(!x&!z|x&z|y)",
"y|z", "(y|z)",
"!x|y|z", "(!x|y|z)",
"x|x", "x",
"!y&!z|x", "(!y&!z|x)",
"!y&z|x", "(!y&z|x)",
"!y|x", "(!y|x)",
"!z&y|x", "(!z&y|x)",
"!z|x", "(!z|x)",
"!y&z|!z&y|x", "(!y&z|!z&y|x)",
"!y|!z|x", "!(!x&y&z)",
"x|y&z", "(x|y&z)",
"!y&!z|x|y&z", "(!y&!z|x|y&z)",
"x|z", "(x|z)",
"!y|x|z", "(!y|x|z)",
"x|y", "(x|y)",
"!z|x|y", "(!z|x|y)",
"x|y|z", "(x|y|z)",
"!x|x", "(!x|x)"};
   while(t--)
    {
        string s;
        cin >> s;
        int mask_st = 0;
        int it = 0;
        for(int i = 0; i < 8; i++)
        {
            if(s[i] == '1')
            {
                mask_st += (1 << i);
            }
        }
        int ind1 = mask_st * 2;
        int ind2 = mask_st * 2 + 1;
        if(cmp(dp[ind1], dp[ind2]))
        {
            cout << dp[ind1] << "\n";
        }
        else{
            cout << dp[ind2] << "\n";
        }
    }
    return 0;
}