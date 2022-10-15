#include <cstdio>
#include <algorithm>

int main()
{
    long long x,y,z;
    scanf("%lld %lld %lld",&x,&y,&z);
    bool b=((x%z+y%z)<z)?true:false;
    printf("%lld %lld",(long long)((x+y)/z),b?0:(long long)(std::min(z-x+x/z*z,z-y+y/z*z)));
    return 0;
}