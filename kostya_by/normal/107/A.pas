program project1;

uses math;

const inf = maxlongint;

type adj = ^gr;
     gr = record
        val, d : longint;
        next : adj;
     end;



var
   rin,bool : array[1..1000] of longint;
   graf : array[1..1000] of adj;
   ans : array[1..1000,1..1000] of longint;
   i,j,k,n,h,m,a,b,c : longint;

procedure add(a,b,c : longint);
var
   p : adj;
begin
     new(p);
     p^.val:=b;
     p^.d:=c;
     p^.next:=graf[a];
     graf[a]:=p;
end;

procedure dfs(v,st,min1 : longint);
var
   h1 : adj;
begin
     bool[v]:=1;
     h1:=graf[v];
     if h1 = nil then begin
        inc(h);
        ans[st,v]:=min1;
        exit;
     end;
     while h1 <> nil do begin
           if bool[h1^.val] = 0 then dfs(h1^.val,st,min(min1,h1^.d));
           h1:=h1^.next;
     end;
end;

begin
     read(n,m);
     for i:=1 to m do begin
         read(a,b,c);
         add(a,b,c);
         rin[b]:=1;
     end;
     h:=0;
     for i:=1 to n do begin
         if rin[i] = 0 then begin
            dfs(i,i,inf);
         end;
     end;
     h:=0;
     for i:=1 to n do begin
         for j:=1 to n do begin
             if i = j then continue;
             if ans[i,j] = 0 then continue;
             inc(h);
         end;
     end;
     writeln(h);
     for i:=1 to n do begin
         for j:=1 to n do begin
             if i = j then continue;
             if ans[i,j] = 0 then continue;
             writeln(i,' ',j,' ',ans[i,j]);
         end;
     end;
end.