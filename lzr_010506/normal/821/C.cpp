#include <bits/stdc++.h>
using namespace std;
char ch[10];
vector<int> p;
int n, x, cnt, ans, d;
int main()
{
    scanf("%d", &n);
    cnt = 1;
    ans = 0;
    for(int i = 1; i <= 2 * n; i ++)
    {
    	scanf("%s", ch);
        if(ch[0] == 'a')
        {
            scanf("%d", &x);
            p.push_back(x);
        }
        else
        {
            if(p.empty());
            else if(p.back() == cnt) p.pop_back();
            else ans ++, p.clear();
            cnt ++;
        }
    }
    cout << ans;
    return 0;
}