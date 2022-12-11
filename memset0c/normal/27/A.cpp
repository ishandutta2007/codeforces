#include<bits/stdc++.h>
using namespace std;
vector<int> vec;
int main() {
    int n;
    scanf("%d", &n);
    for(int i=1;i<=n;i++)
    {
        int k;
        scanf("%d", &k);
        vec.push_back(k);
    }
    for(int i=1;true;i++)
    {
        if(count(vec.begin(),vec.end(),i)==0)
        {cout<<i;break;}
    }
    return 0;
}