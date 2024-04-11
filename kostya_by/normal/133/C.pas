program project1;

var
   a : array[0..1000] of longint;
   st : ansistring;
   i,j,k,n,m : longint;

function reverse(x : longint):longint;
var
   a : array[1..8] of longint;
   i,j,k,res : longint;
begin
     for i:=1 to 8 do begin
         a[i]:=x mod 2;
         x:=x div 2;
     end;
     res:=0;
     for i:=1 to 8 do begin
         res:=res * 2 + a[i];
     end;
     exit(res);
end;

procedure check(first : longint);
var
   i,j,k,n,m,l : longint;
begin
     m:=ord(st[1]);
     k:=reverse(m);
     a[1]:=256 - k;
     writeln(a[1]);
     for i:=2 to length(st) do begin
         m:=ord(st[i]);
         k:=reverse(m);
         l:=(reverse(ord(st[i - 1])) - k + 256) mod 256;
         writeln(l);
     end;
end;

begin
     readln(st);
     n:=length(st);
     //for i:=0 to 256 do begin
         check(i);
     //end;
end.