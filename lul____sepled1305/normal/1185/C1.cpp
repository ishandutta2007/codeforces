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
long long quick[300010];
int main()
{
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
        if(i>0)
        {
            quick[i]=quick[i-1]+a[i];
        }
        else
        {
            quick[0]=a[0];
        }
    }
    //cout<<quick[2];
    if(quick[0]<=m)
    {
        cout<<"0 ";
    }
    for(i=1;i<n;i++)
    {
        k=0;
        s=i-1;
        sort(a,a+i);
        for(j=0;j<=i-1;j++)
        {
            if(quick[i]<=m)
            {
                k++;
                //cout<<"Hooray"<<j;
                break;
            }
            else
            {
                quick[i]-=a[i-1-j];
                /*if(i==4){ cout<<a[0];
                    cout<<quick[i]<<j;}*/
            }
        }
        if(k==0)
        {
            cout<<i<<" ";
        }
        else
        cout<<j<<" ";
    }
    return 0;
}