#include <iostream>
#include <vector>
using namespace std;
bool ex[(1<<18)];
int main()
{
    int n,x;
    scanf("%d%d",&n,&x);
    ex[0]=1;
    vector<int> v({0});
    for (int i=1;i<(1<<n);i++)
    {
        if (ex[i^x])
        continue;
        v.push_back(i);
        ex[i]=1;
    }
    printf("%d\n",v.size()-1);
    for (int i=1;i<v.size();i++)
    printf("%d ",(v[i]^v[i-1]));
}