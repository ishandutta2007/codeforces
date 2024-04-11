#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define pii pair<int, int>

const int maxi = 1e6 + 10;
int a[maxi];
string s;
int n;
vector<int> v[maxi];
int c1, c2, c3;
int same[maxi];

pii move(char x)
{
    if (x == 'L') return {-1, 0};
    if (x == 'R') return {1, 0};
    if (x== 'U') return {0, 1};

    return {0, -1};
}

int check(int x, int y)
{
    int curX = 0;
    int curY = 0;
    for (char i:s)
    {
        pii node = move(i);
        if (x!=curX + node.first || y!= curY + node.second)
        {
            curX+=node.first;
            curY+=node.second;
        }
    }

    return curX==0 && curY==0;
}

void solve()
{
    cin>>s;

    int curX = 0;
    int curY = 0;

    int n = s.size();

    vector<pii> pom;

    pom.pb({100000, 100000});

    for (char i:s)
    {
        pii node = move(i);
        curX+=node.first;
        curY+=node.second;
        pom.pb({curX, curY});
    }

    for (auto i:pom){
        if (check(i.first, i.second))
        {
            printf("%d %d\n", i.first, i.second);
            return;
        }
    }

    printf("0 0\n");
}

int main()
{
    int t;

    cin>>t;

    while(t--)
    {
        solve();
    }
    return 0;
}