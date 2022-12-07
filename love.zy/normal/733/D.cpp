#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int N1 = 400005;
struct qq
{
    int x1, y1, z1, id1;
} aa1[N1];
bool cmp(qq x, qq y)
{
    if(x.x1 != y.x1) return x.x1 < y.x1;
    if(x.y1 != y.y1) return x.y1 < y.y1;
    return x.z1 < y.z1;
}
int ans1, k1, x1, y1, n1, cnt;
void Up222(qq &A,qq	 &B)
{
    if (A.x1 == B.x1 && A.y1 == B.y1 && A.id1 != B.id1)
    {
        int num=min(min(A.x1,A.y1),A.z1+B.z1);
        if (ans1 < num) ans1=num, k1=2, x1=A.id1, y1=B.id1;
    }
}
void solve ()
{

    int n;
    scanf("%d",&n);
    for (int i = 1; i <= n; i ++)
    {
        int a, b, c;
        scanf("%d%d%d",&a,&b,&c);
        if (a > b) swap(a, b);
        if (a > c) swap(a, c);
        if (b > c) swap(b, c);
        int num = min(min(a, b), c);

        aa1[++ cnt].x1 = a;
        aa1[cnt].y1 = b;
        aa1[cnt].z1 = c;
        aa1[cnt].id1 = i;
        aa1[++ cnt].x1 = a;
        aa1[cnt].y1= c;
        aa1[cnt].z1 = b;
        aa1[cnt].id1 = i;
        aa1[++ cnt].x1 = b;
        aa1[cnt].y1 = c;
        aa1[cnt].z1 = a;
        aa1[cnt].id1 = i;

        if (ans1 < num)
        {
            k1= 1;
            x1= i;
            ans1 = num;
        }
    }
    sort(aa1 + 1, aa1 + cnt + 1, cmp);
    for (int i = 1; i <= cnt; i ++)
        for (int j = 1; j <= 1 && i + j <= cnt; j ++)
            Up222(aa1[i], aa1[i + j]);
    if (k1 == 1) printf("1\n%d",x1);
    else printf("2\n%d %d",x1,y1);
}
int main()
{
    solve();
    return 0;
}