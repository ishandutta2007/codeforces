program p1;

var
        bool : array[1..5,1..5] of boolean;
        i,j,k,n,m,a,b : longint;
begin
        read(m);
        for i:=1 to m do begin
                read(a,b);
                bool[a,b]:=true;
                bool[b,a]:=true;
        end;
        for i:=1 to 5 do
                for j:=i + 1 to 5 do
                        for k:=j + 1 to 5 do
                                if (bool[i,j] = bool[j,k]) and (bool[j,k] = bool[i,k]) then begin
                                        writeln('WIN');
                                        halt(0);
                                end;
        writeln('FAIL');
end.