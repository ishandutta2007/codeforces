#include <stdio.h>
#include <vector>
using namespace std;

vector<int> U;
int N,M,W[505];

int main()
{
    scanf ("%d %d",&N,&M);
    for (int i=1;i<=N;i++) scanf ("%d",&W[i]);

    long long s = 0;
    vector<int> in;
    for (int i=1;i<=M;i++){
        int x; scanf ("%d",&x);
        long long all = 0, ab = 0;
        for (int y : in) all += W[y];
        for (int j=0;j<in.size();j++){
            ab += W[in[j]];
            if (in[j] == x){
                ab = all - ab;
                in.erase(in.begin()+j);
                break;
            }
        }
        in.push_back(x);
        s += ab;
    }
    printf ("%lld\n",s);

    return 0;
}