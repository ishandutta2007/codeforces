using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AlgoTraining.Codeforces.E_s
{
    public class FastScanner : StreamReader
    {
        private string[] _line;
        private int _iterator;

        public FastScanner(Stream stream) : base(stream)
        {
            _line = null;
            _iterator = 0;
        }
        public string NextToken()
        {
            if (_line == null || _iterator >= _line.Length)
            {
                _line = base.ReadLine().Split(' ');
                _iterator = 0;
            }
            if (_line.Count() == 0) throw new IndexOutOfRangeException("Input string is empty");
            return _line[_iterator++];
        }
        public int NextInt()
        {
            return Convert.ToInt32(NextToken());
        }
        public long NextLong()
        {
            return Convert.ToInt64(NextToken());
        }
        public float NextFloat()
        {
            return float.Parse(NextToken());
        }
        public double NextDouble()
        {
            return Convert.ToDouble(NextToken());
        }
    }
    class XorSequencesECR14
    {
        public static void Main(string[] args)
        {
            using (FastScanner fs = new FastScanner(new BufferedStream(Console.OpenStandardInput())))
            using (StreamWriter writer = new StreamWriter(new BufferedStream(Console.OpenStandardOutput())))
            {
                int n = fs.NextInt();
                //int n = 100;

                int mod = (int)1e9 + 7;

                long k = fs.NextLong();
                //long k = (long)1e18;

                long[] a = new long[n];

                long[,] D1 = new long[1, n];
                long[,] C = new long[n, n];

                Random rand = new Random();
                for (int i = 0; i < n; i++)
                {
                    D1[0, i] = 1;
                    a[i] = fs.NextLong();
                    //a[i] = rand.Next(1, (int)1e9);
                }
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        C[i, j] = IsValidPair(a[i], a[j]);
                    }
                }
                if (k == 1)
                {
                    writer.WriteLine(n);
                    return;
                }
                long[,] Dk = MatrixProductMod(D1, BinPowMatrixMod(C, k - 1, mod), mod);
                long sum = 0;
                for (int i = 0; i < n; i++)
                {
                    sum += Dk[0, i];
                    sum %= mod;
                }
                writer.WriteLine(sum);
                var s = 0;
            }
        }
        public static int IsValidPair(long a, long b)
        {
            long c = a ^ b;
            int ones = 0;
            while (c != 0)
            {
                if ((c & 1) == 1) ones++;
                c >>= 1;
            }
            return ones % 3 == 0 ? 1 : 0;
        }
        public static long[,] BinPowMatrixMod(long[,] a, long p, long mod) // p >= 1
        {
            if (a.GetLength(0) != a.GetLength(1))
            {
                throw new Exception("Not a square matrix");
            }

            if (p == 1) return a;
            if ((p & 1) == 0)
            {
                long[,] t = BinPowMatrixMod(a, p / 2, mod);
                return MatrixProductMod(t, t, mod);
            }
            else
            {
                return MatrixProductMod(a, BinPowMatrixMod(a, p - 1, mod), mod);
            }
        }

        private static long[,] MultiplyMatricesMod2(long[,] a, long[,] b, long mod)
        {
            if (a.GetLength(1) == b.GetLength(0))
            {
                long[,] c = new long[a.GetLength(0), b.GetLength(1)];
                for (int i = 0; i < c.GetLength(0); i++)
                {
                    for (int j = 0; j < c.GetLength(1); j++)
                    {
                        c[i, j] = 0;
                        for (int k = 0; k < a.GetLength(1); k++)
                        {
                            c[i, j] = c[i, j] + a[i, k] % mod * b[k, j] % mod;
                            c[i, j] %= mod;
                        }
                    }
                }
                return c;
            }
            else
            {
                throw new Exception("Can't multiply because of incompatible sizes");
            }
        }
        private static long[,] MatrixProductMod(long[,] matrixA, long[,] matrixB, long mod)
        {
            int aRows = matrixA.GetLength(0); int aCols = matrixA.GetLength(1);
            int bRows = matrixB.GetLength(0); int bCols = matrixB.GetLength(1);
            if (aCols != bRows)
                throw new Exception("Can't multiply because of incompatible sizes");

            long[,] result = new long[aRows, bCols];

            for (int i = 0; i < aRows; ++i) {
                for (int j = 0; j < bCols; ++j) // each col of B
                    for (int k = 0; k < aCols; ++k) // could use k < bRows
                        result[i, j] = (result[i, j] + matrixA[i, k] * matrixB[k, j]) % mod;
            }

            return result;
        }
    }
}