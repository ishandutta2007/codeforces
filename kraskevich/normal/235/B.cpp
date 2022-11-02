#include <cstdio>

using namespace std;


int main()
{
    double len = 0, res = 0;
    int n;
    
    scanf("%d", & n);
    
    for (int i = 0; i < n; ++i)
    {
        double p;
        
        scanf("%lf", & p);
        
        len = (len + 1) * p;
        res += len * 2 - p;
    }
    
    printf("%lf", res);
    
    return 0;
}