#include <stdio.h>
#include <vector>
using namespace std;

vector<int> x;

int main()
{
    for (int i=2;i<=1000;i++){
        x.push_back(i);
    }
    for (int i=1000;i>=1;i--){
        x.push_back(i);
    }
    printf ("%d\n",x.size());
    for (int p : x) printf ("%d %d %d %d\n",p,1,p,2);

    return 0;
}