#include<bits/stdc++.h>
using namespace std;

vector<int> inp;

int main()
{
    for(int i=1;inp.size()<1000;i++)
        if(i%3&&i%10!=3)inp.push_back(i);

    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;

        int cur;
        scanf("%i",&cur);
        printf("%i\n",inp[cur-1]);
    }

    return 0;
}