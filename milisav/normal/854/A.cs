using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            int n;
            n=Convert.ToInt32(Console.ReadLine());
            int a, b;
            b = n / 2 + 1;
            a = n - b;
            if(a%2==0 && b%2==0)
            {
                a--;
                b++;
            }
            Console.WriteLine(a + " " + b);
        }
    }
}