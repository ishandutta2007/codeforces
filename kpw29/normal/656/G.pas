Var
kitten,n,m,i,j,T:word;l:array[1..50] of word;s:string;
Begin Readln(n, m, T);for i :=1 to n do begin Readln(s);for j := 1 to m do
     if (s[j] = 'Y') then inc(l[j]);
 End;kitten := 0;
 for i:=1 to m do
   if (l[i] >= T) then inc(kitten);
 Writeln(kitten)
End.