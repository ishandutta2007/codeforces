program project1;

var
   names : array[1..16] of string;
   ans : array[1..16] of string;
   bool : array[1..16,1..16] of longint;
   z : array[1..16] of longint;
   i,j,k,l,n,m,num : longint;
   st,s1,s2 : string;

procedure rec(a : longint);
var
   i,j,k : longint;
begin
     if a = n + 1 then begin
        for i:=1 to n do begin
            for j:=1 to n do begin
                if (bool[i,j] = 1) and (z[i] = 1) and (z[j] = 1) then exit;
            end;
        end;
        j:=0;
        for i:=1 to n do j:=j + z[i];
        if j > num then begin
           num:=j;
           k:=0;
           for i:=1 to n do if z[i] = 1 then begin
              inc(k);
              ans[k]:=names[i];
           end;
        end;
     end;
     if a < n + 1 then begin
        for i:=0 to 1 do begin
            z[a]:=i;
            rec(a + 1);
            z[a]:=0;
        end;
     end;
end;

procedure sort;
var
   i,j : longint;
begin
     for i:=1 to n do begin
         for j:=1 to n do begin
             if names[i] < names[j] then begin
                st:=names[i];
                names[i]:=names[j];
                names[j]:=st;
             end;
         end;
     end;
end;

begin
     readln(n,m);
     for i:=1 to n do readln(names[i]);
     sort;
     for i:=1 to m do begin
         readln(st);
         l:=pos(' ',st);
         s1:=copy(st,1,l - 1);
         s2:=copy(st,l + 1,length(st) - l);
         for j:=1 to n do if s1 = names[j] then break;
         for k:=1 to n do if s2 = names[k] then break;
         bool[j,k]:=1;
         bool[k,j]:=1;
     end;
     num:=0;
     rec(1);
     writeln(num);
     for i:=1 to num do writeln(ans[i]);
end.