program project1;

type adj = ^gr;
     gr = record
        key : longint;
        next : adj;
     end;

var
   graf : array[1..100000] of adj;
   bool : array[1..100000] of longint;
   i,n,a,b,c : longint;
   m1,m2,ans : int64;

function happy(x1 : longint):boolean;
var
   x : longint;
begin
     x:=x1;
     while x <> 0 do begin
         if (x mod 10 <> 4) and (x mod 10 <> 7) then exit(false);
         x:=x div 10;
     end;
     exit(true);
end;

procedure add(v1,v2 : longint);
var
   p : adj;
begin
     new(p);
     p^.key:=v2;
     p^.next:=graf[v1];
     graf[v1]:=p;
end;

procedure dfs(v : longint);
var
   h : adj;
begin
     inc(c);
     h:=graf[v];
     bool[v]:=-1;
     while h <> nil do begin
           if bool[h^.key] = 0 then dfs(h^.key);
           h:=h^.next;
     end;
end;

procedure fill(v : longint);
var
   h : adj;
begin
     h:=graf[v];
     bool[v]:=c;
     while h <> nil do begin
           if bool[h^.key] = -1 then fill(h^.key);
           h:=h^.next;
     end;
end;

begin
     read(n);
     for i:=1 to n - 1 do begin
         read(a,b,c);
         if not happy(c) then begin
           add(a,b);
           add(b,a);
         end;;
     end;
     for i:=1 to n do begin
         c:=0;
         if bool[i] = 0 then begin
            dfs(i);
            fill(i);
         end;
     end;
     ans:=0;
     for i:=1 to n do begin
         m1:=n - bool[i];
         m2:=m1 - 1;
         ans:=ans + (m1 * m2);
     end;
     writeln(ans);
end.