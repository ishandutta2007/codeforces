#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n;
char a[N], b[N];
int nxt[N];
void getnxt()
{
    int j = 0;
    nxt[1] = 0;
    for(int i = 2; i <= n; i ++)
    {
        while(j && b[j + 1] != b[i]) j = nxt[j];
        if(b[j + 1] == b[i]) j ++;
        nxt[i] = j;
    }
}
void kmp()
{
    int j = 0;
    for(int i = 1; i <= n; i ++)
    {
        while(j && b[j + 1] != a[i]) j = nxt[j];
        if(b[j + 1] == a[i]) j ++;
    }
    if(j) cout << "NO";
    else cout << "YES";
}
int main()
{
	scanf("%d", &n);
	n --;
    scanf("%s%s", a + 1, b + 1);
    for(int i = 1; i <= n; i ++)
    {
        if(b[i] == 'N') b[i] = 'S';
        else if(b[i] == 'S') b[i] = 'N';
        else if(b[i] == 'W') b[i] = 'E';
        else if(b[i] == 'E') b[i] = 'W';
    }
    for(int i = 1; i <= n / 2; i ++)
    	swap(b[i], b[n + 1 - i]);
    //for(int i = 1; i <= n; i ++)
    //    cout << b[i];
    getnxt();
    kmp();
    return 0;
}