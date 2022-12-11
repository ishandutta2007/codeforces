program project1;

const inf = maxlongint;

var
   st : ansistring;
   n,k,i,j,min,a,b,ans : longint;
   bool : array[1..26] of longint;
begin
     for i:=1 to 26 do bool[i]:=inf;
     readln(st);
     read(k);
     n:=length(st);
     ans:=0;
     for i:=1 to n do begin
         if bool[ord(st[i]) - 96] = inf then bool[ord(st[i]) - 96]:=1 else inc(bool[ord(st[i]) - 96]);
         if bool[ord(st[i]) - 96] = 1 then inc(ans);
     end;
     while ans > 0 do begin
           min:=1;
           for i:=2 to 26 do if bool[i] < bool[min] then min:=i;
           if k - bool[min] >= 0 then begin
              k:=k - bool[min];
              ans:=ans - 1;
              bool[min]:=inf;
           end else break;
     end;
     writeln(ans);
     for i:=1 to n do begin
         if bool[ord(st[i]) - 96] <> inf then write(st[i]);
     end;
end.