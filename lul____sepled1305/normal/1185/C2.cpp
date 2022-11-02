/*
Mezamete wa kurikaesu, nemui asa wa
Eri no tai o kitsuku shime
Kyoushitsu no doa kuguru to hon no sukoshi
Mune o hatte arukidaseru
Sonna nichijou ni fukinukeru kaze

Kikoeta ki ga shita
Kanjita ki ga shitan da
Furuedasu ima kono mune de
Mou kuru ki ga shita
Ikuoku no hoshi ga kiesatteku no o
Miokutta
Te o futta
Yokatta ne, to

Rouka no sumi miorosu, souji no tochuu
Okashi na mono da to omou
Atashi no naka no toki wa tomatteru no ni
Chigau hibi o ikiteru you ni
Hokori wa yuki no you ni furitsumu

Matteru ki ga shita
Yonderu ki ga shitan da
Furuedasu ima kono toki ga
Mitsuketa ki ga shita
Ushinawareta kioku ga yobisamashita
Monogatari
Eien no
Sono owari

Itsu no ma ni ka kakedashiteta
Anata ni te o hikareteta
Kinou wa tooku ashita wa sugu
Sonna atarimae ni kokoro ga odotta

Kikoeta ki ga shita
Kanjita ki ga shitan da
Furuedasu ima kono mune de
Mou kuru ki ga shita
Ikusen no asa o koe
Atarashii hi ga
Matteru ki ga shita
Yonderu ki ga shitan da
Furueteru kono tamashii ga
Mitsuketa ki ga shita
Ikuoku no yume no you ni kiesareru hi o
Miokutta
Te o futta
Arigatou, to
*/
#include<bits/stdc++.h>
using namespace std;
long long int i,j,k,n,m,s;
long long a[300010];
long long t[101];
long long quick,semi;
int main()
{
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
        quick+=a[i];
        semi=quick;
        if(quick<=m)
        {
            cout<<"0 ";
        }
        else
        {
            int ll=0;
            for(j=100;j>0;j--)
            {
                if(semi-j*t[j]<=m)
                {
                    //cout<<semi;
                    cout<<ll+(semi-m+j-1)/j<<" ";
                    //cout<<j;
                    break;
                }
                else
                {
                    semi-=j*t[j];
                    ll+=t[j];
                    //cout<<semi;
                }
            }
        }
        t[a[i]]++;
    }
    return 0;
}