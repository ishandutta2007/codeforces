#include <iostream>

using namespace std;

template<typename _EuclideanRingElement>
    _EuclideanRingElement
    __gcd(_EuclideanRingElement __m, _EuclideanRingElement __n)
    {
      while (__n != 0)
	{
	  _EuclideanRingElement __t = __m % __n;
	  __m = __n;
	  __n = __t;
	}
      return __m;
    }

int main()
{
    int64_t c, h, w, H, W, lcd, ans = 0;
    cin >> c >> h >> H >> w >> W;
    if (W < w)
        swap(h, H), swap(w, W);
    lcd = w * W / __gcd(w, W);
    int64_t tms = max(0ll, c / lcd - 1);
    if (lcd / w * h > lcd / W * H)
        ans = tms * (lcd / w * h);
    else
        ans = tms * (lcd / W * H);
    c -= tms * lcd;
    int64_t am = c / w, nam;
    int64_t uw = am * w;
    int64_t ue = am * h;
    int64_t tans = ue;
    while (am > 0)
    {
        nam = (W + uw - c + w - 1) / w;
        if (am < nam)
            break;
        am -= nam;
        uw -= nam * w;
        ue -= nam * h;
        ue += int64_t((c - uw) / W) * H;
        uw += int64_t((c - uw) / W) * W;
        tans = max(tans, ue);
    }
    cout << ans + tans;
    return 0;
}