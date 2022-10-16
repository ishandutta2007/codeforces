/*
    author:     MarX and ArielxX
    school:     UH
*/

#include <cstdio>
#include <algorithm>


using namespace std;

unsigned long long L[100100];

int main()
{
    unsigned long long total, horas;
    scanf("%lld%lld",&total,&horas);
    for (int i = 0; i < total; ++i)
        scanf("%lld",L + i);

    sort(L,L + total);
    unsigned long long tiempo_total = 0;


    for (int i = 0; i < total ; ++i)
    {
        tiempo_total += L[i]*horas;
        if (horas > 1)
            horas--;
    }
    printf("%lld\n",tiempo_total);
    return 0;
}