#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


void no()
{
    printf("NO\n");
    exit(0);
}
void yes()
{
    printf("YES\n");
    exit(0);
}

int n;
int cntToPlace[13];

vector <int> st;

void tryPlace(int cur)
{
    if (cur == n)
        yes();
    for (int i = 0; i < cur; i++)
    {
        if (cntToPlace[i] > st[cur] || (cntToPlace[i] == st[cur] && cntToPlace[i] + 1 != st[i] ) )
        {
            cntToPlace[i] -= st[cur];
            tryPlace(cur + 1);
            cntToPlace[i] += st[cur];
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    scanf("%d", &n);
    int leafs = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        if (x == 2)
            no();
        if (x == 1)
            leafs++;
        else
            st.push_back(x);
    }
    if (leafs <= n / 2)
        no();

    sort(st.begin(), st.end() );
    reverse(st.begin(), st.end() );
    if (st.size() == 0)
    if (n == 1)
    yes();
    else
    no();
    if (st[0] != n)
        no();
    
    n = st.size();
    //fprintf(stderr, "ok\n");

    for (int i = 0; i < n; i++)
        cntToPlace[i] = st[i] - 1;
    tryPlace(1);
    no();

    

    return 0;
}