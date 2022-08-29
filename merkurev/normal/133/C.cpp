
#include <iostream>
using namespace std;

int main(){
    char c[1005];
    cin.getline(c,1000);
    int x=0,pre=0;
    int i=-1;
    while (c[++i])
    {
        int cur=c[i]+x;
        int r=0;
        for (int i=0;i<8;i++)
        {
            if (cur & 1<<i)
            {
                r+=1<<(7-i);
            }
        }
        cout<<(pre-r+256)%256<<endl;
        pre=r;
    }
    return 0;
}