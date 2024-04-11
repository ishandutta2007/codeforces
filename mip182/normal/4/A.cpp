// x -   
// y -  
// x + y = w
// y = w-x
#include <iostream>
using namespace std;
int main()
{
      int w;
      cin>>w;
int ok=0;
for (int x=1;x<=w;x++)
{
      if (x%2!=0)
            continue;
      int y=w-x;
      if (y%2!=0)
            continue;
      if (y<=0)
            continue;
      ok=1;
}
if (ok==1)
      cout<<"YES";
else
      cout<<"NO";
      }