import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.StringTokenizer;
import java.lang.Math.*;


/**
 *
 * @author Aditya Joshi
 * (mnbvmar tried to give some mods)
 */
 

public class Main 
{
    private static ArrayList<LinkedList<Integer>> distance_oracle;
    private static LinkedList<Edge> answers;
    private static int root, k;
   
    private static int visited_vertices = 0;
    public static void main(String[] args)
    {
        MyScanner sc = new MyScanner();
        int n = sc.nextInt();
        k = sc.nextInt();
        int temp;
       
   
        distance_oracle = new ArrayList<>();
        answers = new LinkedList<>();
        
        distance_oracle.ensureCapacity(n+1);
        for(int i = 0; i <= n; i++)
        {
			distance_oracle.add(new LinkedList<Integer>());
		}
        
        for(int i = 0; i < n; i++)
        {   
            temp = sc.nextInt();
            distance_oracle.get(temp).addLast(i+1);
        }
        
        if(distance_oracle.get(0).size() != 1)
			System.out.println(-1);
        else
        {
            root = (int)distance_oracle.get(0).removeFirst();
            DFS(root, 0);
       
            if(visited_vertices != n) System.out.println(-1);
            else
            {
                System.out.println(answers.size());
                for(Edge edge : answers)
                {
                    System.out.println(edge.one + " " + edge.two);
                    
                }
            }
        
        }
       
    
    }
    
    private static void DFS(int current_node, int distRoot)
    {
        visited_vertices++;
        int max_count = Math.min((current_node == root ? k : k-1),
                                 distance_oracle.get(distRoot + 1).size());
        
        for(int count = 0; count < max_count; count++)
        {
            int neighbour = distance_oracle.get(distRoot + 1).removeFirst();
            
            answers.add(new Edge(current_node, neighbour));
            DFS(neighbour, distRoot + 1);
        }         
    }
    
    
/**********************************************************************/
   
    public static class Node
    {
        int val;
        HashMap<Integer, Integer> neighbours;
        public Node()
        {
            neighbours = new HashMap();
        }
        
    
    }
      
    public static class Edge
    {
        int one, two;
        public Edge(int o, int t)
        {
            one = o;
            two = t;
        }
    }
    public static class MyScanner 
       {
      BufferedReader br;
      StringTokenizer st;
 
      public MyScanner() 
      {
         br = new BufferedReader(new InputStreamReader(System.in));
      }
 
      String next() 
      {
          while (st == null || !st.hasMoreElements()) 
          {
              try 
              {
                  st = new StringTokenizer(br.readLine());
              } catch (IOException e) 
              {
                  e.printStackTrace();
              }
          }
          return st.nextToken();
      }
 
      int nextInt() 
      {
          return Integer.parseInt(next());
      }
 
      long nextLong() 
      {
          return Long.parseLong(next());
      }
 
      double nextDouble() 
      {
          return Double.parseDouble(next());
      }
 
      String nextLine()
      {
          String str = "";
	  try 
          {
	     str = br.readLine();
	  } catch (IOException e) 
          {
	     e.printStackTrace();
	  }
	  return str;
      }

   } 
    
}