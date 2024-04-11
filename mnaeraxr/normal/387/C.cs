using System;
using System.Collections.Generic;

namespace ConsoleApplication1
{
    class Program
    {
        public static void Main()
        {
            string input = Console.ReadLine();
            //if (input.Length > 5000)
            //{
            //    Console.WriteLine(input.Length);
            //    return;
            //}
            var a = new SupraLinkedList(input);
            var c = a.first;
            int total = 1;
            while (true)
            {
                if (c.next == null)
                    break;
                var n = c.next;
                if (c.ge(n))
                {
                    a.doit(n);
                    total++;
                }
                else
                {
                    a.doit(n);
                    total = 1;
                }
            }
            Console.WriteLine(total);
        }
    }

    class SupraLinkedList
    {
        public SLLElement first;

        public SupraLinkedList(string a)
        {
            first = new SLLElement(int.Parse(a[0].ToString()));
            var current = first;
            for (int i = 1; i < a.Length; i++)
            {
                if (a[i] == '0')
                {
                    current.add();
                }
                else
                {
                    var _new = new SLLElement(int.Parse(a[i].ToString()));
                    current.next = _new;
                    _new.prev = current;
                    current = _new;
                }
            }
        }

        public void doit(SLLElement element)
        {
            element.prev.len += element.len;

            if (element.next != null)
                element.next.prev = element.prev;

            element.prev.last.next = element.first;
            //element.last.next = element.first;
            element.prev.next = element.next;
        }
    }

    class SLLElement
    {
        public SLLElement prev, next;
        public int len;
        public myNum first,last;

        public SLLElement(int value)
        {
            len = 1;
            first = new myNum(value);
            last = first;
        }

        public bool ge(SLLElement other)
        {
            if (len == other.len)
            {
                myNum m1 = first;
                myNum m2 = other.first;

                for (int i = 0; i < len; i++)
                {
                    if (m1.value == m2.value)
                    {
                        m1 = m1.next;
                        m2 = m2.next;
                    }
                    else
                    {
                        return m1.value > m2.value;
                    }
                }
                return true;
            }
            return len > other.len;
        }

        public void add()
        {
            var zero = new myNum(0);
            last.next = zero;
            last = zero;
            len++;
        }
    }

    class myNum
    {
        public int value;
        public myNum next;

        public myNum(int value)
        {
            this.value = value;
        }
    }
}