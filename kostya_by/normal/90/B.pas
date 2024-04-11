program project1;

var
   pole : array[1..100,1..100] of char;
   row, col : array[1..100,1..26] of longint;
   i,j,k,n,m : longint;
   ch : char;
begin
     readln(n,m);
     fillchar(row,sizeof(row),0);
     fillchar(col,sizeof(col),0);
     for i:=1 to n do begin
         for j:=1 to m do begin
             read(ch);
             k:=ord(ch) - 96;
             inc(row[i,k]);
             inc(col[j,k]);
             pole[i,j]:=ch;
         end;
         readln;
     end;
     for i:=1 to n do begin
         for j:=1 to m do begin
             k:=ord(pole[i,j]) - 96;
             if (row[i,k] = 1) and (col[j,k] = 1) then write(pole[i,j]);
         end;
     end;
end.