#include <bits/stdc++.h>

using namespace std;

/// Template (una parte horrible del cdigo)

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10; 

pii B[ maxn ];
int A[ maxn ];

/// Esto es un BIT, [sin trucos]

int bit[ maxn ];

void update(int idx, int v){
    while (idx < maxn){
        bit[idx] += v;
        idx += idx & -idx;
    }
}

int query(int idx){
    int answer = 0;
    while (idx){
        answer += bit[ idx ];
        idx -= idx & -idx;
    }
    return answer;
}

/// Fin del BIT

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#ifdef MARX
    freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
#endif

    /// Leo la entrada (esto se entiende :)

    int n; cin >> n;

    for (int i = 0; i < n; ++i){
        cin >> B[i].first;
        B[i].second = i + 1;
    }

    /// Guardo un array con pares donde el primer elemento
    /// es el valor original de la carta y el segundo elemento
    /// es la posicin donde esta ocurre.
    sort(B, B + n);

    /// La idea que vamos a seguir es la siguiente. Vamos primero
    /// a encontrar el orden en que vamos a borrar las cartas. Fijate
    /// que sabemos el orden de los valores que vamos a borrar, pero
    /// el problema es que cuando hay cartas con un mismo valor debemos
    /// encontrar el orden en que estas se eliminan.

    /// Luego de encontrar el orden vamos a ir eliminando carta por carta
    /// y ah es donde uso el BIT. 

    /// ...

    /// En esta primera parte del cdigo lo que hago es calcular el orden
    /// en que voy a eliminar las cartas, fijate que el orden lo estoy
    /// guardando en el array A.

    /// En la variable cur guardo la ltima posicin eliminada (fijate) que
    /// yo enumero las posicines desde 1 as que iniciar con 0 est bien.
    /// La idea de esta variable es que si deseo eliminar un conjunto de nmeros
    /// iguales esto los voy a borrar de forma consecutiva pero quizs rotados,
    /// pues tengo que empezar a borrar a partir del ltimo elemento eliminado.

    /// pnt es para saber cuantos elementos he insertado hasta ahora en A.
    /// fijate que solo lo uso en la lnea """A[ pnt++ ] = ..."""

    int cur = 0, pnt = 0;

    for (int i = 0, j; i < n; i = j){
        /// Este doble for que ves aqu es lineal. Por si no lo has visto
        /// antes te comento lo que hace. Fijo con el valor i la posicin
        /// en el array B del valor que voy a procesar. El valor es B[i].first.
        /// Y con el puntero j me muevo hacia adelante con el for de abajo hasta
        /// encontrar la ltima posicin en B con el mismo valor. Fijate que la
        /// condicin del <for> superior no es i++ como suele ser, sino i = j,
        /// para empezar a partir del prximo valor diferente.
        for (j = i; j < n && B[j].first == B[i].first; ++j);

        /// Aqu proceso todos los elementos del mismo valor.

        int pos = lower_bound(B + i, B + j, pii(B[i].first, cur)) - (B + i);
        int size = j - i;

        for (int k = 0; k < size; ++k, ++pos){
            if (pos == size) pos = 0;
            A[ pnt++ ] = B[ i + pos ].second;
        }

        cur = A[ pnt - 1 ];
    }

    /// Ahora viene la segunda fase que es lo que realmente me preguntaste.
    /// Si ya tenemos guardada la permutacin A, como borrar los elementos de forma
    /// eficiente. La idea es muy simple, si el ltimo elemento que borramos es el 
    /// elemento u y ahora queremos borrar el elemento v, debemos movernos por la pila
    /// por todos los elementos vivos entre u y v. Fijate que u y v los debemos considerar
    /// ciclicos. O sea entre 2 y 5 estn los elementos [2, 3, 4, 5] pero entre 5 y 2
    /// estn los elementos [5, 6, ... n, 1, 2]. Debemos saber contar cuantos elementos
    /// vivos hay en un intervalos (y por vivo me refiero a elementos que no han sido
    /// eliminados). Y para esto es el BIT.

    /// Inicializamos el bit en todas las posiciones con 1. Y vamos apagando las posiciones
    /// en el orden en que vayamos eliminando los elementos.

    for (int i = 1; i <= n; ++i)
        update(i, +1);

    int p = 0;
    int64 answer = 0;

    for (int i = 0; i < n; ++i){
        /// El elemento que queremos borrar ahora es el
        /// elemnto u y el ltimo elemento borrad es el
        /// elemento p.
        int u = A[i];

        int64 add = 0;

        /// Este if es para tener en cuenta si el intervalo es normal o
        /// pasa ciclicamente por ..., n, 1, ...

        if (p < u)
            add = query(u) - query(p);
        else
            add = n - i - (query(p) - query(u)); 


        /// Al final actualizamos todo. La cantidad de elementos vivos
        /// en el camino.
        answer += add;
        /// Borramos el elemento
        update(u, -1);
        /// Y guardamos quien fue el ltimo elemento procesado que es desde
        /// donde nos debemos mover ahora.
        p = u;
    }

    /// Y la parte ms feliz del cdigo ;)
    cout << answer << endl;

    return 0;
}

// GL